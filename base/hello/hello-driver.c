/**
 * hello-driver.c
 * 
 * This file is a base linux driver example.
*/

#include <linux/init.h>
#include <linux/module.h>


static int __init hello_init(void)
{
    printk("Kernel: hello init.\n");

    return 0;
}

static void __exit hello_exit(void)
{
    printk("Kernel: hello exit.\n");
}

module_init(hello_init);
module_exit(hello_exit);

MODULE_LICENSE("GPL-2.0");
