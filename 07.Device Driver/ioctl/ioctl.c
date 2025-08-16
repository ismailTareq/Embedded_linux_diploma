#include "file-operation.h"

#define DRIVER_NAME "my_gpio_number"
#define DRIVER_CLASS "my_gpio_class"

MODULE_LICENSE("GPL");
MODULE_AUTHOR("ismail tarek");
MODULE_DESCRIPTION("this is a mf robbery bitch");

struct my_data{
    dev_t dev;
    struct cdev my_cdev;
    struct class *my_class;
    struct device *my_device;
    struct file_operations fops;
    struct cdev my_device_cdev;

}my_GPIO_data={
    .fops = {
        .owner = THIS_MODULE,
        .open = open_handler,
        .release = release_handler,
        .read = read_handler,
        .write = write_handler,
        .unlocked_ioctl = ioctl_handler,
    }
};

static int my_init(void)
{
    int ret = 0;
    printk(KERN_ERR "Hello BITCH\n");
    ret = alloc_chrdev_region(&my_GPIO_data.dev, 0, 1, DRIVER_NAME);
    if (ret < 0) {
        printk(KERN_ERR "Failed to allocate char device region\n");
        return ret;
    }
    printk(KERN_INFO "Allocated char device region with major number %d and minor number %d\n", MAJOR(my_GPIO_data.dev), MINOR(my_GPIO_data.dev));

    cdev_init(&my_GPIO_data.my_cdev, &my_GPIO_data.fops);
    ret = cdev_add(&my_GPIO_data.my_cdev, my_GPIO_data.dev, 1);
    if(ret != 0)
    {
        printk(KERN_ERR "Failed to add cdev\n");
        goto CHARACTER_ERROR;
    }
    if((my_GPIO_data.my_class = class_create(DRIVER_CLASS)) == NULL)
    {
        printk(KERN_ERR "Failed to create class\n");
        goto CLASS_ERROR;
    }
    if((my_GPIO_data.my_device = device_create(my_GPIO_data.my_class, NULL, my_GPIO_data.dev, NULL, "test_file")) == NULL)
    {
        printk(KERN_ERR "Failed to create device\n");
        goto DEVICE_ERROR;
    }
    printk(KERN_INFO "Device created successfully\n");
    return 0;
DEVICE_ERROR:
    class_destroy(my_GPIO_data.my_class);
CLASS_ERROR:
    cdev_del(&my_GPIO_data.my_cdev);
CHARACTER_ERROR:
    unregister_chrdev_region(my_GPIO_data.dev, 1);
    return -1;
}

static void my_exit(void)
{
    gpio_set_value(pin_number, 0); // Turn off the LED
    gpio_free(pin_number);
    device_destroy(my_GPIO_data.my_class, my_GPIO_data.dev);
    class_destroy(my_GPIO_data.my_class);
    cdev_del(&my_GPIO_data.my_cdev);
    unregister_chrdev_region(my_GPIO_data.dev, 1);
    printk(KERN_ERR "Goodbye BITCH\n");
}

module_init(my_init);
module_exit(my_exit);
