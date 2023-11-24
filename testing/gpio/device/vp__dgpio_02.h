
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/device/gpiodevice.h>

struct VP__DGPIO_02 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        for (int i = 0; i < 10; i ++) {
            register_device( new GpioDevice() );

            if (gpio_device_count() != i + 2)
                return false;
        }
        
        return true;
    }

    const char* getName     () override { return "VP__DGPIO_02"; }
    const char* getCategory () override { return "GPIO Device"; }
};

#endif
