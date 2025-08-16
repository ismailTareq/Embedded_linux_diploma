#ifndef IOCTL_FILE_OPERATION_H
#define IOCTL_FILE_OPERATION_H

#include <linux/gpio.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include "ioctl-write.h"

extern uint32_t pin_number;
int open_handler(struct inode *inode, struct file *file);
int release_handler(struct inode *inode, struct file *file);
ssize_t read_handler(struct file *file, char __user *userbuffer, size_t count, loff_t *offset);
ssize_t write_handler(struct file *file, const char __user *userbuffer, size_t count, loff_t *offset);
long ioctl_handler(struct file *file, unsigned int cmd, unsigned long arg);

#endif // IOCTL_FILE_OPERATION_H
