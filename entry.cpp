
#include "vpico/stdlib.h"
#include "vpico/hardware/gpio.h"

int main () {
    setup_default_uart();
    printf("Hello, World !\n");
    printf("Showed at time : %lldus\n", get_absolute_time());
    sleep_us(250);
    printf("Showed at time : %lldus\n", get_absolute_time());
    sleep_ms(10);
    printf("Showed at time : %lldms\n", us_to_ms( get_absolute_time() ));

    const uint LED_PIN = PICO_DEFAULT_LED_PIN;
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, true);

    for (int i = 0; i < 4; i ++) {
        gpio_put(LED_PIN, 1);
        sleep_ms(250);
        gpio_put(LED_PIN, 0);
        sleep_ms(250);
    }

    return 0;
}
