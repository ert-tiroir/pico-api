
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/device/gpiodevice.h>
#include <vpico/device/devices/pico/led.h>
#include <vpico/stdlib.h>

#include <vpico/hardware/gpio.h>

struct VP__DLED_02 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        PicoLED_Device* device = (PicoLED_Device*) get_gpio_device(0);

        __device_gpio_put(PICO_DEFAULT_LED_PIN, false);
        device->onPin();
        if (device->getLEDState() != false) return false;
        __device_gpio_put(PICO_DEFAULT_LED_PIN, true);
        device->onPin();
        if (device->getLEDState() != true) return false;
        __device_gpio_put(PICO_DEFAULT_LED_PIN, false);
        device->onPin();
        if (device->getLEDState() != false) return false;
        __device_gpio_put(PICO_DEFAULT_LED_PIN, true);
        device->onPin();
        if (device->getLEDState() != true) return false;

        return true;
    }

    const char* getName     () override { return "VP__DLED_02"; }
    const char* getCategory () override { return "Pico LED Device"; }
};

#endif