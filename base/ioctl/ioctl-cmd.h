/**
 * ioctl-driver.h
 * This file is ioctl command define head file.
 * 
 * License - GPL-2.0.
*/

#ifndef __IOCTL_DRIVER_H__
#define __IOCTL_DRIVER_H__

#include <linux/types.h>


#define HELLO_IOC_MAGIC         'K'

#define HELLO_IOCRESET          _IO(HELLO_IOC_MAGIC,  0xA0)         /* No parameter.         */
#define HELLO_IOCID             _IOR(HELLO_IOC_MAGIC, 0xA1, __s32)  /* Device ID, read only. */
#define HELLO_IOCRANDOM         _IOW(HELLO_IOC_MAGIC, 0xA2, __s32)  /* Random, write only.   */
#define HELLO_IOCEXCHANGE       _IOWR(HELLO_IOC_MAGIC,0xA3, __s32)  /* Read and write.       */

#define HELLO_IOCADD            _IOW(HELLO_IOC_MAGIC, 0xA4, struct hello_factor) /* + */
#define HELLO_IOCSUB            _IOW(HELLO_IOC_MAGIC, 0xA5, struct hello_factor) /* - */
#define HELLO_IOCMUL            _IOW(HELLO_IOC_MAGIC, 0xA6, struct hello_factor) /* * */
#define HELLO_IOCDIV            _IOW(HELLO_IOC_MAGIC, 0xA7, struct hello_factor) /* / */
#define HELLO_IOCMOD            _IOW(HELLO_IOC_MAGIC, 0xA8, struct hello_factor) /* % */
#define HELLO_IOCRESULT         _IOR(HELLO_IOC_MAGIC, 0xA9, struct hello_factor) /* = */


struct hello_factor {
    int a;
    int b;
};


#endif /* __IOCTL_DRIVER_H__ */
