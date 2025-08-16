#include <linux/module.h>
#include <linux/init.h>
#include <linux/mod_devicetable.h>
#include <linux/property.h>
#include <linux/platform_device.h>
#include <linux/of_device.h>
#include <linux/gpio/consumer.h>
#include <linux/proc_fs.h>
#include <linux/leds.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ismail tarek");
MODULE_DESCRIPTION("testing the fuckin device tree");

static int dt_probe(struct platform_device *pdev);
static void dt_remove(struct platform_device *pdev);

static struct of_device_id my_dt_ids[] = {
    { .compatible = "ismail-led", },
    { /* sentinel */ }
};

static struct gpio_desc *my_led = NULL;
static struct led_classdev my_led_cdev;
static void brightness_handler(struct led_classdev *led_cdev, enum led_brightness brightness)
{
    gpiod_set_value(my_led, (brightness && 0x01));
}
MODULE_DEVICE_TABLE(of, my_dt_ids);

static struct platform_driver my_dt_driver = {
    .probe = dt_probe,
    .remove = dt_remove,
    .driver = {
        .name = "my_device_driver",
        .of_match_table = my_dt_ids,
    },
};

//static struct proc_dir_entry *proc_entry;

static ssize_t mywrite(struct file *file, const char __user *user_buffer, size_t count, loff_t *offset)
{
    char val;
    
    if (copy_from_user(&val, user_buffer, 1))  // Safely read 1 byte
        return -EFAULT;
    
    if (val == '1' || val == '0')
        gpiod_set_value(my_led, val - '0');
    
    return count;
}
// static struct proc_ops my_proc_ops = {
//     .proc_write = mywrite,
// };

static int dt_probe(struct platform_device *pdev)
{
    struct device *dev = &pdev->dev;
    const char *label;
    int ret, value;

    printk(KERN_INFO "Probing device tree driver\n");

    // Check DT properties
    if (!device_property_present(dev, "label") ||
        !device_property_present(dev, "my_value") ||
        !device_property_present(dev, "led-gpio")) {
        printk(KERN_ERR "Missing required DT properties\n");
        return -ENXIO;
    }

    // Read properties
    ret = device_property_read_string(dev, "label", &label);
    if (ret) {
        printk(KERN_ERR "Failed to read label: %d\n", ret);
        return ret;
    }
    printk(KERN_INFO "Device label: %s\n", label);

    ret = device_property_read_u32(dev, "my_value", &value);
    if (ret) {
        printk(KERN_ERR "Failed to read my_value: %d\n", ret);
        return ret;
    }
    printk(KERN_INFO "my_value: %d\n", value);

    // Get GPIO
    my_led = devm_gpiod_get(dev, "led", GPIOD_OUT_LOW);
    if (IS_ERR(my_led)) {
        ret = PTR_ERR(my_led);
        printk(KERN_ERR "Failed to get led-gpio: %d\n", ret);
        return ret;
    }

    gpiod_set_value(my_led, value);
    printk(KERN_INFO "ALL DONE BABE\n");
    // // Create proc entry
    // proc_entry = proc_create("my_proc_entry", 0666, NULL, &my_proc_ops);
    // if (!proc_entry) {
    //     printk(KERN_ERR "Failed to create proc entry\n");
    //     return -ENOMEM;
    // }
    my_led_cdev.name = label;
    my_led_cdev.brightness_set = brightness_handler;
    ret = led_classdev_register(NULL, &my_led_cdev);
    if (ret < 0) {
        printk(KERN_ERR "Failed to register LED class device\n");
        return -1;
    }
    return 0;
}

static void dt_remove(struct platform_device *pdev)
{
    printk(KERN_INFO "Removing device tree driver\n");
    gpiod_put(my_led);
    //proc_remove(proc_entry);
}

static int __init my_init(void)
{
    printk(KERN_INFO "Initializing my device driver\n");
    if(platform_driver_register(&my_dt_driver)) {
        printk(KERN_ERR "Failed to register platform driver\n");
        return -1;
    }
    return 0;
}

static void __exit my_exit(void)
{
    printk(KERN_INFO "Exiting my device driver\n");
    platform_driver_unregister(&my_dt_driver);
}

module_init(my_init);
module_exit(my_exit);

