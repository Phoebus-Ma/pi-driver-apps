/**
 * test-app.c
 *
 * This file is ioctl example.
*/

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

#include "ioctl-cmd.h"


#define DEVICE_NAME             "/dev/ioctl_driver"


int main(void)
{
    int fd  = -1;
    int32_t val32 = 0;
    int64_t val64 = 100;

    struct hello_factor factor = {
        .a = 2,
        .b = 1
    };

    // Open device driver.
    fd = open(DEVICE_NAME, O_RDWR);
    if (-1 == fd) {
        printf("Error in open.\n");
        return -1;
    }

    // 1. Reset random.
    if (ioctl(fd, HELLO_IOCRESET)) {
        printf("Error in HELLO_IOCRESET.\n");
    }

    printf("Reset random sucessfully.\n");

    // 2. Set random.
    val32 = 13579;
    ioctl(fd, HELLO_IOCRANDOM, &val32);

    printf("Set random sucessfully.\n");

    // 3. Get device id.
    val32 = 0;
    ioctl(fd, HELLO_IOCID, &val32);
    printf("Device ID: 0x%x.\n", val32);

    // 4. Write and read.
    ioctl(fd, HELLO_IOCEXCHANGE, &val64);
    printf("value: %ld.\n", val64);

    // 5. Calculate add.
    // also, you can use add/sub/mul/div/mod.
    val32 = 0;
    ioctl(fd, HELLO_IOCADD, &factor);
    ioctl(fd, HELLO_IOCRESULT, &val32);
    printf("The a + b = %d.\n", val32);

    // Close device driver.
    close(fd);

    return 0;
}
