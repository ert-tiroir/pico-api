
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/device/gpiodevice.h>
#include <vpico/device/devices/pico/led.h>
#include <vpico/stdlib.h>

#include <vpico/hardware/gpio.h>

struct VP__DLED_01 : public TestCase {
private:
    std::string expected = "\"[DEBUG] : \"\"The LED is now on.\\n\"\"[DEBUG] : \"\"The LED is now off\\n\"\"[DEBUG] : \"\"The LED is now on.\\n\"";
public:
    void setup () override {}
    bool run   () override {
        PicoLED_Device* device = (PicoLED_Device*) get_gpio_device(0);

        __device_gpio_put(PICO_DEFAULT_LED_PIN, false);
        device->onPin();
        __device_gpio_put(PICO_DEFAULT_LED_PIN, true);
        device->onPin();
        __device_gpio_put(PICO_DEFAULT_LED_PIN, false);
        device->onPin();
        __device_gpio_put(PICO_DEFAULT_LED_PIN, true);
        device->onPin();

        #ifdef TESTING
        if (get_cout_buffer() != expected)
            return false;
        #endif

        return true;
    }

    const char* getName     () override { return "VP__DLED_01"; }
    const char* getCategory () override { return "Pico LED Device"; }
};

#endif