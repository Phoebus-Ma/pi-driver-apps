/**
 * base-driver.c
 * 
 * This file is write and read global buffer driver example.
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/fs.h>


#define MIN(a, b)               ((a) < (b) ? (a) : (b))
#define MAX_BUFFER_LEN          255
#define DRIVER_DEVICE           "base_device"
#define DRIVER_CLASS            "base_class"
#define DRIVER_NAME             "base_driver"


struct hello_object {
    unsigned int major;
    struct class *class;
    struct device *device;
    char buf[MAX_BUFFER_LEN + 1];
};

struct hello_object *hello_drv = NULL;


/**
 * hello_open - open device.
*/
static int
hello_open(struct inode *inode , struct file *file)
{
    memset(hello_drv->buf, 0, MAX_BUFFER_LEN + 1);

    return 0;
}

/**
 * hello_close - close device.
*/
static int
hello_close(struct inode *inode, struct file *file)
{
    memset(hello_drv->buf, 0, MAX_BUFFER_LEN + 1);

    return 0;
}

/**
 * hello_read - User read from driver local buffer.
*/
static ssize_t
hello_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
    size_t ret = 0;
    int len = MIN(count, MAX_BUFFER_LEN);

    hello_drv->buf[0] = 'A';
    ret = copy_to_user(buffer, hello_drv->buf, len);

    return (len - ret);
}

/**
 * hello_write - User write to driver local buffer.
*/
static ssize_t
hello_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
    size_t ret = 0;
    int len = MIN(count, MAX_BUFFER_LEN);

    ret = copy_from_user(hello_drv->buf, buffer, len);
    printk("%s: Write %s.\n", DRIVER_NAME, hello_drv->buf);

    return (len - ret);
}

struct file_operations hello_fops = {
    .owner   = THIS_MODULE,
    .open    = hello_open,
    .release = hello_close,
    .read    = hello_read,
    .write   = hello_write
};

static int __init
hello_init(void)
{
    // 1. Allocate driver object.
    hello_drv = kzalloc(sizeof(struct hello_object), GFP_KERNEL);
    if (NULL == hello_drv) {
        printk("%s: Error in kzalloc.\n", DRIVER_NAME);
        goto out1;
    }

    // 2. Register char device.
    hello_drv->major = register_chrdev(0, DRIVER_DEVICE, &hello_fops);
    if (hello_drv->major < 0) {
        printk("%s: Error in register_chrdev.\n", DRIVER_NAME);
        goto out2;
    }

    // 3. Create device class.
    hello_drv->class = class_create(THIS_MODULE, DRIVER_CLASS);
    if (IS_ERR(hello_drv->class)) {
        printk("%s: Error in class_create.\n", DRIVER_NAME);
        goto out3;
    }

    // 4. Create device.
    hello_drv->device = device_create(hello_drv->class, NULL, MKDEV(hello_drv->major, 0), NULL, DRIVER_NAME);
    if (IS_ERR(hello_drv->device)) {
        printk("%s: Error in device_create.\n", DRIVER_NAME);
        goto out4;
    }

    printk("%s: Create device driver successful.\n", DRIVER_NAME);

    return 0;

out4:
    class_destroy(hello_drv->class);

out3:
    unregister_chrdev(hello_drv->major, DRIVER_DEVICE);

out2:
    kfree(hello_drv);

out1:
    return -1;
}

static void __exit
hello_exit(void)
{
    device_destroy(hello_drv->class, MKDEV(hello_drv->major, 0));
    class_destroy(hello_drv->class);
    unregister_chrdev(hello_drv->major, DRIVER_DEVICE);
    kfree(hello_drv);

    printk("%s: Uninstalled.\n", DRIVER_NAME);
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
