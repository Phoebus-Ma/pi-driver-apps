/**
 * AT24C02 eeprom i2c example.
 *
 * License - MIT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <unistd.h>


#define I2C_DEV                 "/dev/i2c-1"
#define EEPROM_ADDR             0x50


/**
 * eeprom_write_byte - Write a byte to EEPROM. 
*/
int eeprom_write_byte(int fd, unsigned char addr, unsigned char data)
{
    unsigned char buf[2] = {addr, data};
    if (write(fd, buf, 2) != 2) {
        perror("Write failed");
        return -1;
    }

    // Need delay for writing.
    usleep(5000);

    return 0;
}

/**
 * eeprom_read_byte - Read a byte from EEPROM.
*/
int eeprom_read_byte(int fd, unsigned char addr, unsigned char *data)
{
    if (write(fd, &addr, 1) != 1) {
        perror("Set read address failed");
        return -1;
    }

    if (read(fd, data, 1) != 1) {
        perror("Read failed");
        return -1;
    }

    return 0;
}

int main()
{
    int fd = open(I2C_DEV, O_RDWR);
    if (fd < 0) {
        perror("Open I2C device failed");
        return 1;
    }

    if (ioctl(fd, I2C_SLAVE, EEPROM_ADDR) < 0) {
        perror("Set I2C address failed");
        close(fd);
        return 1;
    }

    // Write data.
    if (eeprom_write_byte(fd, 0x00, 0x66) == 0) {
        printf("Write success\n");
    }

    // Read data.
    unsigned char value;
    if (eeprom_read_byte(fd, 0x00, &value) == 0) {
        printf("Read value: 0x%02X\n", value);
    }

    close(fd);

    return 0;
}
