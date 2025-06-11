/**
 * main.c
 * This file is base cdev driver example.
 * 
 * License - GPL-2.0.
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/fs.h>


#define DRIVER_DEVICE           "cdev_device"
#define DRIVER_CLASS            "cdev_class"
#define DRIVER_NAME             "cdev_driver"

#define DEVICE_MAJOR            0
#define MIN(a, b)               ((a) < (b) ? (a) : (b))


struct hello_object {
    int flag;
    dev_t devno;
    struct cdev *cdev;
    struct class *class;
    struct device *device;
};

struct hello_object *hello_drv = NULL;


/**
 * hello_open - open device.
*/
static int
hello_open(struct inode *inode , struct file *file)
{
    hello_drv->flag = 0xAB;

    return 0;
}

/**
 * hello_close - close device.
*/
static int
hello_close(struct inode *inode, struct file *file)
{
    hello_drv->flag = 0x00;

    return 0;
}

/**
 * hello_read - User read from driver local buffer.
*/
static ssize_t
hello_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
    size_t ret = 0;
    int len = MIN(count, sizeof(int));

    ret = copy_to_user(buffer, &hello_drv->flag, len);

    return (len - ret);
}

/**
 * hello_write - User write to driver local buffer.
*/
static ssize_t
hello_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
    size_t ret = 0;
    int len = MIN(count, sizeof(int));

    ret = copy_from_user(&hello_drv->flag, buffer, len);
    printk("%s: Write 0x%x.\n", DRIVER_NAME, hello_drv->flag);

    return (len - ret);
}

struct file_operations cdev_fops = {
    .owner   = THIS_MODULE,
    .open    = hello_open,
    .release = hello_close,
    .read    = hello_read,
    .write   = hello_write
};

static int __init
hello_init(void)
{
    int ret = 0;

    // 1. Allocate driver object memory space.
    hello_drv = kzalloc(sizeof(struct hello_object),  GFP_KERNEL);
    if (NULL == hello_drv) {
        ret = -ENOMEM;
        printk("%s: Error in kzalloc.\n", DRIVER_NAME);
        goto out1;
    }

    // 2. Request device number.
    if (DEVICE_MAJOR > 0) {
        hello_drv->devno = MKDEV(DEVICE_MAJOR, 0);
        ret = register_chrdev_region(hello_drv->devno, 1, DRIVER_DEVICE);
    }
    else {
        ret = alloc_chrdev_region(&hello_drv->devno, 0, 1, DRIVER_DEVICE);
    }

    if (ret < 0) {
        printk("%s: Error in register char device.\n", DRIVER_NAME);
        goto out2;
    }

    // 3. Create char device.
    hello_drv->cdev = cdev_alloc();
    if (NULL == hello_drv->cdev) {
        ret = -ENOMEM;
        goto out3;
    }

    cdev_init(hello_drv->cdev, &cdev_fops);

    ret = cdev_add(hello_drv->cdev, hello_drv->devno, 1);
    if (ret < 0) {
        printk("%s: Error in cdev_add.\n", DRIVER_NAME);
        goto out3;
    }

    // 4. Create class.
    // Note: If use linux-6.x or later, delete parameter 1: THIS_MODULE.
    hello_drv->class = class_create(THIS_MODULE, DRIVER_CLASS);
    if (IS_ERR(hello_drv->class)) {
        printk("%s: Error in class_create.\n", DRIVER_NAME);
        goto out4;
    }

    // 5. Create device.
    hello_drv->device = device_create(hello_drv->class, NULL, hello_drv->devno, NULL, DRIVER_NAME);
    if (IS_ERR(hello_drv->device)) {
        printk("%s: Error in device_create.\n", DRIVER_NAME);
        goto out5;
    }

    printk("%s: driver installed.\n", DRIVER_NAME);

    return 0;

out5:
    class_destroy(hello_drv->class);

out4:
    if (hello_drv->cdev != NULL) {
        cdev_del(hello_drv->cdev);
    }

out3:
    unregister_chrdev_region(hello_drv->devno, 1);

out2:
    if (hello_drv != NULL) {
        kfree(hello_drv);
    }

out1:
    return ret;
}

static void __exit
hello_exit(void)
{
    device_destroy(hello_drv->class, hello_drv->devno);
    class_destroy(hello_drv->class);
    cdev_del(hello_drv->cdev);
    unregister_chrdev_region(hello_drv->devno, 1);
    kfree(hello_drv);

    printk("%s: driver unistalled.\n", DRIVER_NAME);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
