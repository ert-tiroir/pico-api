
#include <vpico/device/gpiodevice.h>

#ifdef VIRTUAL

#include <vector>
#include "vpico/device/devices/pico/led.h"

std::vector<GpioDevice*> devices = { new PicoLED_Device() };

int gpio_device_count () {
    return devices.size();
}
GpioDevice* get_gpio_device (int id) {
    return devices[id];
}
void register_device (GpioDevice* device) {
    devices.push_back(device);
}

void reset_gpio_devices () {
    devices = { new PicoLED_Device() };
}

#endif
