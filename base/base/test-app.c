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


#define DEVICE_NAME             "/dev/base_driver"
#define MAX_BUF_LEN             16


int main(void)
{
    int fd  = -1;
    int ret = -1;
    char buf[MAX_BUF_LEN] = "hello world";

    // Open device driver.
    fd = open(DEVICE_NAME, O_RDWR);
    if (-1 == fd) {
        printf("Error in open.\n");
        goto out1;
    }

    // Write data to driver.
    ret = write(fd, buf, strlen(buf));
    if (ret < 0) {
        printf("Error in write.\n");
        goto out2;
    }

    // Read data from driver.
    ret = read(fd, buf, MAX_BUF_LEN - 1);
    if (ret < 0) {
        printf("Error in read.\n");
        goto out2;
    }

    printf("Read from kernel: %s.\n", buf);

    // Close device driver.
    close(fd);

    return 0;

out2:
    close(fd);

out1:
    return -1;
}
