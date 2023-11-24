
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/device/gpiodevice.h>
#include <vector>
#include <vpico/device/devices/pico/led.h>

struct VP__DGPIO_04 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        return gpio_device_count() == 1
            && !((PicoLED_Device*) get_gpio_device(0))->getLEDState();
    }

    const char* getName     () override { return "VP__DGPIO_04"; }
    const char* getCategory () override { return "GPIO Device"; }
};

#endif
