
#include <vpico/device/devices/pico/led.h>

#ifdef VIRTUAL

#include <vpico/hardware/gpio.h>
#include <vpico/stdlib.h>

void PicoLED_Device::onPin () {
    if (__device_gpio_get(PICO_DEFAULT_LED_PIN) == LED_State) return ;

    LED_State = __device_gpio_get(PICO_DEFAULT_LED_PIN);

    if (LED_State) { __debug( "The LED is now on.\n" ); }
    else { __debug ( "The LED is now off\n" ); }
}

bool PicoLED_Device::getLEDState () {
    return LED_State;
}

#endif
