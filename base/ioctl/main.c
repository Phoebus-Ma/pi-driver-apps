/**
 * main.c
 * This file is base iotctl driver example.
 * 
 * License - GPL-2.0.
*/

#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/types.h>

#include "ioctl-cmd.h"
#include "calculate.h"


#define MIN(a, b)               ((a) < (b) ? (a) : (b))
#define MAX_BUFFER_LEN          255
#define DRIVER_DEVICE           "ioctl_device"
#define DRIVER_CLASS            "ioctl_class"
#define DRIVER_NAME             "ioctl_driver"
#define DEVICE_ID               0x12345678


struct hello_object {
    uint32_t major;
    uint32_t device_id;
    uint32_t random_num;
    struct class *class;
    struct device *device;
    char buf[MAX_BUFFER_LEN + 1];
};

union ioctl_param {
    uint32_t num;
    struct hello_factor factor;
};


struct hello_object *hello_drv = NULL;
static int32_t calcute_result = 0;
static int64_t value = 0;

/**
 * hello_open - open device.
*/
static int
hello_open(struct inode *inode , struct file *file)
{
    hello_drv->device_id = DEVICE_ID;
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

/**
 * hello_ioctl - User use io control read and write local buffer.
*/
static long
hello_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
    union ioctl_param params;

    if (_IOC_TYPE(cmd) != HELLO_IOC_MAGIC) {
        return -ENOTTY;
    }

    switch (cmd)
    {
    /* Read and write. */
    case HELLO_IOCRESET:
        hello_drv->random_num = 0x1010;
        printk("%s: Random reset: 0x%x.\n", DRIVER_NAME, hello_drv->random_num);
        break;

    /* READ only. */
    case HELLO_IOCID:
        if (copy_to_user((int __user *)arg, &hello_drv->device_id, sizeof(hello_drv->device_id))) {
            printk("%s: Error in ioctl HELLO_IOCID.\n", DRIVER_NAME);
            return -EFAULT;
        }
        break;

    /* Write only. */
    case HELLO_IOCRANDOM:
        if (copy_from_user(&params, (int __user *)arg, sizeof(params))) {
            printk("%s: Error in ioctl HELLO_IOCADD.\n", DRIVER_NAME);
            return -EFAULT;
        }

        hello_drv->random_num = params.num;
        printk("%s: random number: %d.\n", DRIVER_NAME, hello_drv->random_num);
        break;

    case HELLO_IOCEXCHANGE:
        if (copy_from_user(&value, (int __user *)arg, sizeof(value))) {
            printk("%s: Error in ioctl HELLO_IOCADD.\n", DRIVER_NAME);
            return -EFAULT;
        }

        value = value * 2;
        printk("%s: HELLO_IOCEXCHANGE value * 2 = %lld.\n", DRIVER_NAME, value);

        if (copy_to_user((int __user *)arg, &value, sizeof(value))) {
            printk("%s: Error in ioctl HELLO_IOCID.\n", DRIVER_NAME);
            return -EFAULT;
        }
        break;

    /* Write only. */
    case HELLO_IOCADD:
        if (copy_from_user(&params, (struct hello_factor *)arg, sizeof(params))) {
            printk("%s: Error in ioctl HELLO_IOCADD.\n", DRIVER_NAME);
            return -EFAULT;
        }

        calcute_result = hello_add(params.factor.a, params.factor.b);
        break;

    /* Write only. */
    case HELLO_IOCSUB:
        if (copy_from_user(&params, (struct hello_factor *)arg, sizeof(params))) {
            printk("%s: Error in ioctl HELLO_IOCSUB.\n", DRIVER_NAME);
            return -EFAULT;
        }

        calcute_result = hello_sub(params.factor.a, params.factor.b);
        break;

    /* Write only. */
    case HELLO_IOCMUL:
        if (copy_from_user(&params, (struct hello_factor *)arg, sizeof(params))) {
            printk("%s: Error in ioctl HELLO_IOCMUL.\n", DRIVER_NAME);
            return -EFAULT;
        }

        calcute_result = hello_mul(params.factor.a, params.factor.b);
        break;

    /* Write only. */
    case HELLO_IOCDIV:
        if (copy_from_user(&params, (struct hello_factor *)arg, sizeof(params))) {
            printk("%s: Error in ioctl HELLO_IOCDIV.\n", DRIVER_NAME);
            return -EFAULT;
        }

        calcute_result = hello_div(params.factor.a, params.factor.b);
        break;

    /* Write only. */
    case HELLO_IOCMOD:
        if (copy_from_user(&params, (struct hello_factor *)arg, sizeof(params))) {
            printk("%s: Error in ioctl HELLO_IOCMOD.\n", DRIVER_NAME);
            return -EFAULT;
        }

        calcute_result = hello_mod(params.factor.a, params.factor.b);
        break;

    /* Read only. */
    case HELLO_IOCRESULT:
        if (copy_to_user((int *)arg, &calcute_result, sizeof(calcute_result))) {
            printk("%s: Error in ioctl HELLO_IOCRESULT.\n", DRIVER_NAME);
            return -EFAULT;
        }
        break;

    default:
        break;
    }

    return 0;
}

struct file_operations ioctl_fops = {
    .owner   = THIS_MODULE,
    .open    = hello_open,
    .release = hello_close,
    .read    = hello_read,
    .write   = hello_write,
    .unlocked_ioctl = hello_ioctl
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
    hello_drv->major = register_chrdev(0, DRIVER_DEVICE, &ioctl_fops);
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
