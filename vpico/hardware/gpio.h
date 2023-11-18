
#include <vpico/const.h>

#ifndef VIRTUAL
#include "hardware/gpio.h"
#else

#include <cstdint>

using uint = unsigned int;

// GPIO initialized but does not have a direction
#define GPIO_EXISTS 2
// GPIO not initialized
#define GPIO_NONE -1
// GPIO that can be used for output data
#define GPIO_OUT 1
// GPIO that can be used for inputting data
#define GPIO_IN 0

#define GPIO_HIGH 1
#define GPIO_LOW 0

// According to the raspberry pi pico, the GPIO 25 represents the led.
#define PICO_DEFAULT_LED_PIN 25

const int NB_GPIOS = (int) 30;

void gpio_init (uint gpio);
void gpio_set_dir (uint gpio, bool out);

bool gpio_get (uint gpio);
void gpio_put (uint gpio, int value);

#endif
