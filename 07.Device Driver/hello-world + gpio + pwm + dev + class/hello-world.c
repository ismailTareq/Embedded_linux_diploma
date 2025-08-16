#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/fs.h>
#include <linux/cdev.h>
//#include <linux/gpio.h>
#include <linux/pwm.h>
#include <linux/kernel.h>

#define SIZE 15
#define SIZE_READ 3
//#define Led_Pin 588
//#define BTN_Pin 588
static unsigned char hello_buffer[SIZE] = "";
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ismail tarek");
MODULE_DESCRIPTION("this is a mf robbery bitch");

static int open_driver(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");
    return 0;
}
static int release_driver(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");
    return 0;
}
static ssize_t read_driver(struct file *file, char __user *userbuffer, size_t count, loff_t *offset)
{
    int not_copied = 0;
    //int temp[SIZE_READ]= {0};
    printk(KERN_INFO "Reading from device\n");
    printk(KERN_INFO "%s: the count to read is %ld \n", __func__, count);
    printk(KERN_INFO "%s: the offset is %lld \n", __func__, *offset);
    if (count + *offset > SIZE) {
        count = SIZE - *offset; // Adjust count if it exceeds buffer size
    }
    //printk(KERN_INFO "the value of BTN is %d\n", gpio_get_value(BTN_Pin));
    // temp[0] = gpio_get_value(BTN_Pin)+ '0'; // Convert to char
    // temp[1] = '\n'; // Add newline character
    // not_copied = copy_to_user(userbuffer, &temp[*offset], count);
    not_copied = copy_to_user(userbuffer, &hello_buffer[*offset], count);
    if(not_copied)
    {
        return -1;
    }
    *offset = count; // Update the offset
    printk(KERN_INFO "%s: not_copied = %d\n", __func__, not_copied);
    printk(KERN_INFO "%s: the message is %s\n", __func__, userbuffer);
    return 0;
}
static ssize_t write_driver(struct file *file, const char __user *userbuffer, size_t count, loff_t *offset)
{
    int not_copied = 0;
    int value = 0;
    printk(KERN_INFO "Writing to device\n");
    printk(KERN_INFO "%s: the count to write is %ld \n", __func__, count);
    printk(KERN_INFO "%s: the offset is %lld \n", __func__, *offset);
    if (count + *offset > SIZE) {
        count = SIZE - *offset; // Adjust count if it exceeds buffer size
    }
    if (!count) {
        printk(KERN_INFO "no space\n");
        return -1; // No data to write
    }
    not_copied = copy_from_user(&hello_buffer[*offset], userbuffer, count);
    if (kstrtol_from_user(userbuffer, count -1, 0, &value) == 0) {
        printk(KERN_INFO "Value received: %d\n", value);
    } else {
        printk(KERN_ERR "Failed to convert user input to integer\n");
    }
    pwm_config(pwm_led, value * 1000000, 1000000000); // Set PWM duty cycle based on user input
    // switch(hello_buffer[0])
    // {
    //     case '1':
    //         gpio_set_value(Led_Pin, 1); 
    //         printk(KERN_INFO "LED turned ON\n");
    //         break;
    //     case '0':
    //         gpio_set_value(Led_Pin, 0);
    //         printk(KERN_INFO "LED turned OFF\n");
    //         break;
    //     default:
    //         printk(KERN_INFO "Invalid command for LED\n");
    // }
    if(not_copied)
    {
        return -1;
    }
    *offset = count; // Update the offset
    printk(KERN_INFO "%s: not_copied = %zu\n", __func__, count);
    printk(KERN_INFO "%s: the message is %s\n", __func__, hello_buffer);
    return count;
}
dev_t dev;
struct cdev my_cdev;
struct class *my_class;
struct device *my_device;
struct file_operations fops = {
    .owner = THIS_MODULE,
    .open = open_driver, // Define your open function here
    .release = release_driver, // Define your release function here
    .read = read_driver, // Define your read function here
    .write = write_driver, // Define your write function here
};

struct pwm_device *pwm_led = NULL;
u32 pwm_high = 500000000; // 500 ms

//int num = 0;
//module_param(num, int, S_IRUGO);
//MODULE_PARM_DESC(num, "An integer parameter");
//int major_number = 0;
//module_param(major_number, int, S_IRUGO);
//MODULE_PARM_DESC(major_number, "Major number for the device");

static int hello_world_init(void)
{
    //printk(KERN_INFO "Hello, world! num = %d\n", num);
    int ret;
    ret = alloc_chrdev_region(&dev, 0, 1, "test_devicenumber");
    if (ret < 0) {
        printk(KERN_ERR "Failed to allocate char device region\n");
        return ret;
    }
    printk(KERN_INFO "Allocated char device region with major number %d and minor number %d\n", MAJOR(dev), MINOR(dev));
    
    cdev_init(&my_cdev, &fops);
    ret = cdev_add(&my_cdev, dev, 1);
    if(ret != 0)
    {
        printk(KERN_ERR "Failed to add cdev\n");
        goto CHARACTER_ERROR;
    }
    if((my_class = class_create("class_test")) == NULL)
    {
        printk(KERN_ERR "Failed to create class\n");
        goto CLASS_ERROR;
    }
    if((my_device = device_create(my_class, NULL, dev, NULL, "test_file")) == NULL)
    {
        printk(KERN_ERR "Failed to create device\n");
        goto DEVICE_ERROR;
    }
    // if(gpio_request(Led_Pin, "LED GPIO") < 0)
    // {
    //     printk(KERN_ERR "Failed to request GPIO for LED\n");
    //     goto GPIO_ERROR;
    // }
    // if(gpio_direction_output(Led_Pin, 0) < 0)
    // {
    //     printk(KERN_ERR "Failed to set GPIO direction for LED\n");
    //     goto GPIO_DIR_ERROR;
    // }
    // if(gpio_request(BTN_Pin, "Button GPIO") < 0)
    // {
    //     printk(KERN_ERR "Failed to request GPIO for Button\n");
    //     goto GPIO_ERROR;
    // }
    // if(gpio_direction_input(BTN_Pin) < 0)
    // {
    //     printk(KERN_ERR "Failed to set GPIO direction for Button\n");
    //     goto GPIO_BTN_ERROR;
    // }
    pwm_led = pwm_request(0, "pwm_led");
    if (IS_ERR(pwm_led)) {
        printk(KERN_ERR "Failed to request PWM for LED\n");
        goto GPIO_ERROR;
    }
    pwm_config(pwm_led, pwm_high, 1000000000);
    pwm_enable(pwm_led);
    printk(KERN_INFO "Device created successfully\n");
    return 0;
// GPIO_BTN_ERROR:
//     gpio_free(BTN_Pin);
// GPIO_DIR_ERROR:
//     gpio_free(Led_Pin);
GPIO_ERROR:
    device_destroy(my_class, dev);
DEVICE_ERROR:
    class_destroy(my_class);
CLASS_ERROR:
    cdev_del(&my_cdev);
CHARACTER_ERROR:
    unregister_chrdev_region(dev, 1);
    return -1;
}

static void hello_world_exit(void)
{
    // gpio_set_value(Led_Pin, 0); // Turn off the LED
    // gpio_free(Led_Pin); // Free the GPIO
    // gpio_free(BTN_Pin); // Free the Button GPIO
    pwm_disable(pwm_led);
    cdev_del(&my_cdev);
    class_destroy(my_class);
    device_destroy(my_class, dev);
    unregister_chrdev_region(dev, 1);
    printk(KERN_INFO "Goodbye, world!\n");
}

module_init(hello_world_init);
module_exit(hello_world_exit);