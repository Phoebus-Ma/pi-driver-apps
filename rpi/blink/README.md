
# Introduction

Implementing LED blinking in different ways.


# Blink

1. gpiod

Use libgpiod, only the application is needed, no driver is written.

2. gpio

Include application and driver, primitive methods operate on gpio.

3. leds

Use linux driver leds subsystem.


# License

The applications use the MIT license, and the drivers use the GPL-2.0 license.
