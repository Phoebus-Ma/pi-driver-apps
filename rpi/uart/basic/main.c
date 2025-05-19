/**
 * Uart send and receive example.
 *
 * License - MIT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <string.h>
#include <errno.h>


#define UART_DEV                "/dev/serial0" // default uart dev node (soft link).
#define BAUDRATE                B115200        // baudrate (defaukt 115200 bps).


/**
 * uart_init - Initialize uart.
*/
int uart_init()
{
    int uart_fd = open(UART_DEV, O_RDWR | O_NOCTTY);

    if (uart_fd < 0) {
        perror("Error in open uart.");

        return -1;
    }

    struct termios options;
    tcgetattr(uart_fd, &options);
    cfsetispeed(&options, BAUDRATE);
    cfsetospeed(&options, BAUDRATE);

    options.c_cflag |= (CLOCAL | CREAD);        // Local mode, enable receive.
    options.c_cflag &= ~PARENB;                 // No parity.
    options.c_cflag &= ~CSTOPB;                 // 1 bit stop.
    options.c_cflag &= ~CSIZE;
    options.c_cflag |= CS8;                     // 8 bit data.
    options.c_lflag &= ~(ICANON | ECHO | ISIG); // Raw input mode.
    options.c_iflag &= ~(IXON | IXOFF | IXANY); // Disable software flow control.
    options.c_oflag &= ~OPOST;                  // Raw output mode.

    tcflush(uart_fd, TCIOFLUSH);

    if (tcsetattr(uart_fd, TCSANOW, &options) != 0) {
        perror("Error in configure uart.");
        close(uart_fd);

        return -1;
    }

    return uart_fd;
}

/**
 * uart_send - Send data.
*/
void uart_send(int fd, const char *data)
{
    ssize_t len = write(fd, data, strlen(data));
    if (len < 0) {
        perror("Error in send data.");
    }
    else {
        printf("Sent %zd Bytes: %s\n", len, data);
    }

    // Wait for data to be completely sent.
    tcdrain(fd);
}

/**
 * uart_receive - Receive data (Blocking mode).
*/
void uart_receive(int fd)
{
    char buffer[256];
    ssize_t len = read(fd, buffer, sizeof(buffer) - 1);

    if (len < 0) {
        perror("Error in receive data.");
    }
    else if (len == 0) {
        printf("No data arrived.\n");
    }
    else {
        buffer[len] = '\0';
        printf("Receive %zd Bytes: %s\n", len, buffer);
    }
}

int main()
{
    int uart_fd = uart_init();

    if (uart_fd < 0)
        return EXIT_FAILURE;

    // Self sending self receiving test (TXD and RXD short circuit).
    const char *test_data = "Hello World!\n";
    uart_send(uart_fd, test_data);

    // Data stabilize
    usleep(100000);

    uart_receive(uart_fd);

    close(uart_fd);

    return EXIT_SUCCESS;
}
