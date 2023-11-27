# Virtual Pico

The goal of this project is to recreate a "virtual machine"-like simulation of the raspberry pi pico by replacing the entire pico stdlib by a virtual pico standard library. This happens at compilation when the VIRTUAL flag is passed to the compilator, otherwise, it just adds the entire stdlib of pico into vpico/stdlib.h.

The developpement of the project has been stopped in favor of using a real raspberry pi, feel free to reuse the existing code or to contribute to it. The features that were added are testing, general purpose input output, validation of simple uart between the pico and a connected computer.

# Example

Blinking the LED :

```c++
// This file must always be included so that vpico works
#include "vpico/stdlib.h"

int main() {
    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    while (true) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }
}
```
