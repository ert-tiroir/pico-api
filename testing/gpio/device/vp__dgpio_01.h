
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/device/gpiodevice.h>

struct VP__DGPIO_01 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        register_device( new GpioDevice() );
        return gpio_device_count() == 2;
    }

    const char* getName     () override { return "VP__DGPIO_01"; }
    const char* getCategory () override { return "GPIO Device"; }
};

#endif
