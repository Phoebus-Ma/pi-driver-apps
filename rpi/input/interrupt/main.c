/**
 * Button interrupt example.
 *
 * License - MIT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <gpiod.h>
#include <unistd.h>
#include <signal.h>


#define GPIO_CHIP               "gpiochip0" // Default gpio chip.
#define BUTTON_PIN              17          // GPIO 17.


volatile sig_atomic_t stop = 0;

/**
 * Signal function.
*/
void signal_handler(int sig)
{
    stop = 1;
}

int main()
{
    struct gpiod_chip *chip;
    struct gpiod_line *button_line;
    int ret;

    // Register signal function (Ctrl + C to quit).
    signal(SIGINT, signal_handler);

    // 1. Open the gpio chip.
    chip = gpiod_chip_open_by_name(GPIO_CHIP);

    if (!chip) {
        perror("Error in open gpio chip.");

        return EXIT_FAILURE;
    }

    // 2. Get gpio line.
    button_line = gpiod_chip_get_line(chip, BUTTON_PIN);

    if (!button_line) {
        perror("Error in get gpio line.");
        gpiod_chip_close(chip);

        return EXIT_FAILURE;
    }

    // 3. Configure gpio to input direction, enable pull up mode, Falling trigger.
    ret = gpiod_line_request_falling_edge_events(button_line, "button-interrupt");
    if (ret < 0) {
        perror("Error in config interrupt.");
        gpiod_line_release(button_line);
        gpiod_chip_close(chip);

        return EXIT_FAILURE;
    }

    // 4. Loop for interrupt events.
    while (!stop)
    {
        // Timeout waiting for 1 sec (Non-blocking).
        struct timespec ts = {1, 0};
        ret = gpiod_line_event_wait(button_line, &ts);

        if (ret < 0) {
            perror("Error in wait events.");
            break;
        }
        else if (ret == 1) {
            // Read event.
            struct gpiod_line_event event;
            ret = gpiod_line_event_read(button_line, &event);
            if (ret < 0) {
                perror("Error in read events.");
                continue;
            }

            // Key anti-shake: wait after event is detected 50 ms reconfirmation status.
            usleep(50000);
            int val = gpiod_line_get_value(button_line);

            // Confirm button still pressed.
            if (val == 0) {
                printf("Key pressed (time: %ld.%09ld Second(s))\n",
                       event.ts.tv_sec, event.ts.tv_nsec);
            }
        }
    }

    // 5. Release resource.
    gpiod_line_release(button_line);
    gpiod_chip_close(chip);

    return EXIT_SUCCESS;
}
