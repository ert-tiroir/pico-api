#pragma once

#ifdef VIRTUAL

struct GpioDevice {
    virtual void onPin () {};
};

int gpio_device_count ();
GpioDevice* get_gpio_device (int id);
void register_device (GpioDevice* device);
void reset_gpio_devices ();

#endif
