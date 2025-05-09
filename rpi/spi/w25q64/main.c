/**
 * W25Q64 spi flash example.
 *
 * License - MIT.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/spi/spidev.h>


#define SPI_DEVICE "/dev/spidev0.0"
#define SPI_SPEED 500000
#define PAGE_SIZE 256
#define SECTOR_SIZE 4096


/**
 * spi_transfer - Send command.
*/
int spi_transfer(int fd, uint8_t *tx, uint8_t *rx, size_t len)
{
    struct spi_ioc_transfer tr = {
        .tx_buf   = (unsigned long)tx,
        .rx_buf   = (unsigned long)rx,
        .len      = len,
        .speed_hz = SPI_SPEED,
        .bits_per_word = 8,
    };

    return ioctl(fd, SPI_IOC_MESSAGE(1), &tr);
}

/**
 * w25q64_write_enable - Write enable.
*/
void w25q64_write_enable(int fd)
{
    uint8_t cmd = 0x06;
    spi_transfer(fd, &cmd, NULL, 1);
}

/**
 * w25q64_erase_sector - erase flash (4KiB).
*/
void w25q64_erase_sector(int fd, uint32_t addr)
{
    uint8_t cmd[4] = {0x20, addr >> 16, addr >> 8, addr};

    w25q64_write_enable(fd);
    spi_transfer(fd, cmd, NULL, 4);

    // Wait for erase complete (also can read status register).
    sleep(1);
}

/**
 * w25q64_page_program - Write a page (max 256 byte).
*/
void w25q64_page_program(int fd, uint32_t addr, uint8_t *data, size_t len)
{
    uint8_t cmd[4 + PAGE_SIZE] = {0x02, addr >> 16, addr >> 8, addr};

    w25q64_write_enable(fd);
    memcpy(&cmd[4], data, len);
    spi_transfer(fd, cmd, NULL, 4 + len);

    // Wait for write complete.
    usleep(5000);
}

/**
 * w25q64_read_data - Read data.
*/
void w25q64_read_data(int fd, uint32_t addr, uint8_t *buf, size_t len)
{
    uint8_t cmd[4] = {0x03, addr >> 16, addr >> 8, addr};
    uint8_t dummy[len + 4];

    memset(dummy, 0, sizeof(dummy));
    memcpy(dummy, cmd, 4);

    spi_transfer(fd, dummy, buf, len + 4);

    // Remove first 4 byte command response.
    memmove(buf, buf + 4, len);
}

int main()
{
    uint8_t  mode  = SPI_MODE_0;
    uint32_t speed = SPI_SPEED;
    uint32_t addr  = 0x000000;
    uint8_t write_data[PAGE_SIZE] = "Hello, W25Q64!";
    uint8_t read_data[PAGE_SIZE]  = {0};

    int fd = open(SPI_DEVICE, O_RDWR);
    if (fd < 0) {
        perror("Open SPI device failed");
        return 1;
    }

    ioctl(fd, SPI_IOC_WR_MODE, &mode);
    ioctl(fd, SPI_IOC_WR_MAX_SPEED_HZ, &speed);

    printf("Erasing sector...\n");
    w25q64_erase_sector(fd, addr);

    printf("Writing data...\n");
    w25q64_page_program(fd, addr, write_data, strlen((char *) write_data));

    printf("Reading back...\n");
    w25q64_read_data(fd, addr, read_data, strlen((char *) write_data));

    printf("Read result: %s\n", read_data);

    close(fd);

    return 0;
}
