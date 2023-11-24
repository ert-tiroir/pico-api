
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/device/gpiodevice.h>
#include <vector>

struct VP__DGPIO_03 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        std::vector<GpioDevice*> devices;
        for (int i = 0; i < 10; i ++) {
            GpioDevice* device = new GpioDevice();

            devices.push_back(device);
            register_device(device);
        }
        
        if (gpio_device_count() != 11) return false;
        for (int i = 0; i < 10; i ++)
            if (devices[i] != get_gpio_device(i + 1))
                return false;

        return true;
    }

    const char* getName     () override { return "VP__DGPIO_03"; }
    const char* getCategory () override { return "GPIO Device"; }
};

#endif
