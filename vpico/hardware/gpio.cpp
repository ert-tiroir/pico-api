
#include "vpico/hardware/gpio.h"

#ifdef VIRTUAL

#include <vector>
#include "vpico/stdlib.h"

#include "vpico/device/gpiodevice.h"

std::vector<int>  GPIO_STATE (NB_GPIOS, GPIO_NONE);
std::vector<bool> GPIO_VALUE (NB_GPIOS, false);

void gpio_init (uint gpio) {
    if (gpio >= NB_GPIOS || gpio < 0)  __danger( "The GPIO %d is out of bounds for initialization\n", gpio );
    if (GPIO_STATE[gpio] != GPIO_NONE) __danger( "The GPIO %d is already initialized\n", gpio );

    GPIO_STATE[gpio] = GPIO_EXISTS;
}

void gpio_set_dir (uint gpio, bool out) {
    if (gpio >= NB_GPIOS || gpio < 0)  __danger( "The GPIO %d is out of bounds for direction modification\n", gpio );
    if (GPIO_STATE[gpio] == GPIO_NONE) __danger( "The GPIO %d is not initialized\n", gpio );
    
    GPIO_STATE[gpio] = out ? GPIO_OUT : GPIO_IN;
}

bool gpio_get (uint gpio) {
    if (gpio >= NB_GPIOS || gpio < 0)    __danger( "The GPIO %d is out of bounds to retrieve value\n", gpio );
    if (GPIO_STATE[gpio] == GPIO_NONE)   __danger( "The GPIO %d is not initialized\n", gpio );
    if (GPIO_STATE[gpio] == GPIO_EXISTS) __danger( "The GPIO %d has no direction yet\n", gpio );
    if (GPIO_STATE[gpio] == GPIO_OUT)    __danger( "The GPIO %d has direction OUT and cannot retrieve the value\n", gpio );

    return GPIO_VALUE[gpio];
}
bool __device_gpio_get (uint gpio) { return GPIO_VALUE[gpio]; }
void gpio_put (uint gpio, int value) {
    if (gpio >= NB_GPIOS || gpio < 0)    __danger( "The GPIO %d is out of bounds to set the value\n", gpio );
    if (GPIO_STATE[gpio] == GPIO_NONE)   __danger( "The GPIO %d is not initialized\n", gpio );
    if (GPIO_STATE[gpio] == GPIO_EXISTS) __danger( "The GPIO %d has no direction yet\n", gpio );
    if (GPIO_STATE[gpio] == GPIO_IN)     __danger( "The GPIO %d has direction IN and cannot set the value\n", gpio );

    GPIO_VALUE[gpio] = value != 0;

    for (int id = 0; id < gpio_device_count(); id ++)
        get_gpio_device(id)->onPin();
}
void __device_gpio_put (uint gpio, int value) {
    GPIO_VALUE[gpio] = value != 0;
}

void reset_gpio () {
    for (int i = 0; i < NB_GPIOS; i ++) {
        GPIO_STATE[i] = GPIO_NONE;
        GPIO_VALUE[i] = false;
    }
}

#endif
