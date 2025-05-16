/**
 * Button example.
 *
 * License - MIT.
 */

#include <stdio.h>
#include <stdlib.h>
#include <gpiod.h>
#include <unistd.h>


#define GPIO_CHIP               "gpiochip0" // Default gpio chip.
#define BUTTON_PIN              17          // GPIO 17.


int main()
{
    int ret;
    struct gpiod_chip *chip;
    struct gpiod_line *button_line;

    // 1. Open gpio chip.
    chip = gpiod_chip_open_by_name(GPIO_CHIP);

    if (!chip) {
        perror("Error in open the gpio chip.");

        return EXIT_FAILURE;
    }

    // 2. Get the GPIO line (button input).
    button_line = gpiod_chip_get_line(chip, BUTTON_PIN);

    if (!button_line) {
        perror("Error in get goio line.");
        gpiod_chip_close(chip);

        return EXIT_FAILURE;
    }

    // 3.Config gpio direction to input, enable pull up mode (Prevent key shaking).
    ret = gpiod_line_request_input_flags(button_line, "button-demo",
                                         GPIOD_LINE_REQUEST_FLAG_BIAS_PULL_UP);

    if (ret < 0) {
        perror("Error in input direction.");
        gpiod_line_release(button_line);
        gpiod_chip_close(chip);

        return EXIT_FAILURE;
    }

    // 4. Loop for get gpio value.
    while (1)
    {
        int val = gpiod_line_get_value(button_line);
        if (val < 0) {
            perror("Error in read gpio value.");
            break;
        }

        // Low value is key pressed.
        if (val == 0) {
            printf("Key pressed !\n");
            // Optional: delay for prevent key shaking.
            usleep(50000);

            // Loop for wait key release.
            while (!gpiod_line_get_value(button_line))
                usleep(10000);
        }

        // 10 ms apart.
        usleep(10000);
    }

    // 5. Release resource.
    gpiod_line_release(button_line);
    gpiod_chip_close(chip);

    return EXIT_SUCCESS;
}
