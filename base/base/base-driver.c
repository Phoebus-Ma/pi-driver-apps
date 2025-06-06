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


struct base_object {
    unsigned int major;
    struct class *class;
    struct device *device;
    char buf[MAX_BUFFER_LEN + 1];
};

struct base_object *base_drv = NULL;

/**
 * base_read - User read from driver local buffer.
*/
static ssize_t
base_read(struct file *file, char __user *buffer, size_t count, loff_t *ppos)
{
    size_t ret = 0;
    int len = MIN(count, MAX_BUFFER_LEN);

    base_drv->buf[0] = 'A';
    ret = copy_to_user(buffer, base_drv->buf, len);

    return (len - ret);
}

/**
 * base_write - User write to driver local buffer.
*/
static ssize_t
base_write(struct file *file, const char __user *buffer, size_t count, loff_t *ppos)
{
    size_t ret = 0;
    int len = MIN(count, MAX_BUFFER_LEN);

    ret = copy_from_user(base_drv->buf, buffer, len);
    printk("%s: Write %s.\n", DRIVER_NAME, base_drv->buf);

    return (len - ret);
}

/**
 * base_open - open device.
*/
static int
base_open(struct inode *inode , struct file *file)
{
    memset(base_drv->buf, 0, MAX_BUFFER_LEN + 1);

    return 0;
}

/**
 * base_close - close device.
*/
static int
base_close(struct inode *inode, struct file *file)
{
    memset(base_drv->buf, 0, MAX_BUFFER_LEN + 1);

    return 0;
}

struct file_operations base_fops = {
    .owner   = THIS_MODULE,
    .open    = base_open,
    .release = base_close,
    .read    = base_read,
    .write   = base_write
};

static int __init
base_init(void)
{
    // 1. Allocate driver object.
    base_drv = kzalloc(sizeof(struct base_object), GFP_KERNEL);
    if (NULL == base_drv) {
        printk("%s: Error in kzalloc.\n", DRIVER_NAME);
        goto out1;
    }

    // 2. Register char device.
    base_drv->major = register_chrdev(0, DRIVER_DEVICE, &base_fops);
    if (base_drv->major < 0) {
        printk("%s: Error in register_chrdev.\n", DRIVER_NAME);
        goto out2;
    }

    // 3. Create device class.
    base_drv->class = class_create(THIS_MODULE, DRIVER_CLASS);
    if (IS_ERR(base_drv->class)) {
        printk("%s: Error in class_create.\n", DRIVER_NAME);
        goto out3;
    }

    // 4. Create device.
    base_drv->device = device_create(base_drv->class, NULL, MKDEV(base_drv->major, 0), NULL, DRIVER_NAME);
    if (IS_ERR(base_drv->device)) {
        printk("%s: Error in device_create.\n", DRIVER_NAME);
        goto out4;
    }

    printk("%s: Create device driver successful.\n", DRIVER_NAME);

    return 0;

out4:
    class_destroy(base_drv->class);

out3:
    unregister_chrdev(base_drv->major, DRIVER_DEVICE);

out2:
    kfree(base_drv);

out1:
    return -1;
}

static void __exit
base_exit(void)
{
    device_destroy(base_drv->class, MKDEV(base_drv->major, 0));
    class_destroy(base_drv->class);
    unregister_chrdev(base_drv->major, DRIVER_DEVICE);
    kfree(base_drv);

    printk("%s: Uninstalled.\n", DRIVER_NAME);
}

module_init(base_init);
module_exit(base_exit);

MODULE_LICENSE("GPL");
