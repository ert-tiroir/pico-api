
#include <vpico/device/gpiodevice.h>

#ifdef VIRTUAL

struct PicoLED_Device : public GpioDevice {
private:
    bool LED_State = false;
public:
    void onPin () override;
};

#endif
