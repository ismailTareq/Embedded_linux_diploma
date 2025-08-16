#include "file-operation.h"

#define SIZE 255
char buffer[SIZE] = {0};
size_t bufer_pointer = 0;
uint32_t pin_number = 588;

int open_handler(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device opened\n");
    return 0;
}
int release_handler(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device closed\n");
    return 0;
}
ssize_t read_handler(struct file *file, char __user *userbuffer, size_t count, loff_t *offset)
{
    printk(KERN_INFO "called but it's a pin dumass\n");
    return -ENOSYS; // Not implemented
}

long ioctl_handler(struct file *file, unsigned int cmd, unsigned long arg)
{
    uint8_t new_pin;
    
    switch (cmd) {
        case WRITE_PIN:
            gpio_set_value(pin_number, 0); // Reset pin before setting new value
            if (copy_from_user(&new_pin, (uint8_t __user *)arg, sizeof(new_pin)))
            {   
                printk(KERN_ERR "Failed to copy data from user space\n");
                pin_number = 21; // Reset pin number on error
            }
            else
            {
                printk(KERN_INFO "Setting pin number to %d\n", new_pin);
            }
    }

    if(gpio_request(pin_number, "LED GPIO") < 0)
    {
        printk(KERN_ERR "Failed to request GPIO for LED\n");
        return -1; // GPIO already in use
    }
    if(gpio_direction_output(pin_number, GPIOF_OUT_INIT_LOW) < 0)
    {
        printk(KERN_ERR "Failed to set GPIO direction for LED\n");
        gpio_free(pin_number);
        return -1; // Failed to set direction
    }
    printk(KERN_INFO "Using GPIO %d\n", pin_number);
    
    return 0;
}

ssize_t write_handler(struct file *file, const char __user *userbuffer, size_t count, loff_t *offset)
{
    int not_copied = 0;
    char value = 0;
    printk(KERN_INFO "Write handler called\n");
    not_copied = copy_from_user(&value, userbuffer, sizeof(value));
    switch(value)
    {
        case '1':
            gpio_set_value(pin_number, 1);
            printk(KERN_INFO "LED turned ON\n");
            break;
        case '0':
            gpio_set_value(pin_number, 0);
            printk(KERN_INFO "LED turned OFF\n");
            break;
        default:
            printk(KERN_INFO "Invalid command for LED\n");
    }
   
    return count;
}
