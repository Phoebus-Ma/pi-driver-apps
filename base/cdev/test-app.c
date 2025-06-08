/**
 * test-app.c
 * 
 * This file is write and read driver example.
*/

#include <stdio.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>


#define DEVICE_NAME             "/dev/cdev_driver"
#define MAX_BUF_LEN             16


int main(void)
{
    int fd  = -1;
    int ret = -1;
    int value = 0;

    // Open device driver.
    fd = open(DEVICE_NAME, O_RDWR);
    if (-1 == fd) {
        printf("Error in open.\n");
        goto out1;
    }

    // Read data from driver.
    ret = read(fd, &value, sizeof(value));
    if (ret < 0) {
        printf("Error in read.\n");
        goto out2;
    }

    printf("Read from kernel 1: 0x%x.\n", value);

    // Write data to driver.
    value = 0x56;
    ret = write(fd, &value, sizeof(value));
    if (ret < 0) {
        printf("Error in write.\n");
        goto out2;
    }

    // Read data from driver.
    ret = read(fd, &value, sizeof(value));
    if (ret < 0) {
        printf("Error in read.\n");
        goto out2;
    }

    printf("Read from kernel 2: 0x%x.\n", value);

    // Close device driver.
    close(fd);

    return 0;

out2:
    close(fd);

out1:
    return -1;
}
