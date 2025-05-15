/**
 * LED blink example.
 *
 * License - MIT.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gpiod.h>


#define GPIO_CHIP       "/dev/gpiochip0"
#define GPIO_LED        3


int main()
{
    int ret = 0;
    struct gpiod_chip *gpiochip;
    struct gpiod_line *gpioline;

    // Open driver.
    gpiochip = gpiod_chip_open(GPIO_CHIP);

    if (NULL == gpiochip) {
        printf("Error in gpiod_chip_open.\n");
        ret = -1;
        goto out1;
    }

    // Get gpio.
    gpioline = gpiod_chip_get_line(gpiochip, GPIO_LED);

    if (NULL == gpioline) {
        printf("Error in gpiod_chip_get_line.\n");
        ret = -1;
        goto out2;
    }

    // Set gpio direction.
    ret = gpiod_line_request_output(gpioline, "gpio", 0);

    if (ret != 0) {
        printf("Error in gpiod_line_request_output.\n");
        ret = -1;
        goto out2;
    }

    // Blink.
    for (int i = 0; i < 10; i++) {
        printf("%d times.\n", i);

        gpiod_line_set_value(gpioline, 1);
        sleep(1);

        gpiod_line_set_value(gpioline, 0);
        sleep(1);
    }

    // Release.
    gpiod_line_release(gpioline);

out2:
    gpiod_chip_close(gpiochip);

out1:
    return ret;
}
