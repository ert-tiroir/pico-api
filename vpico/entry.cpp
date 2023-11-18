
#include "vpico/stdlib.h"

int main () {
    setup_default_uart();
    printf("Hello, World !\n");
    printf("Showed at time : %lldus\n", get_absolute_time());
    sleep_us(250);
    printf("Showed at time : %lldus\n", get_absolute_time());
    sleep_ms(10);
    printf("Showed at time : %lldms\n", us_to_ms( get_absolute_time() ));
    return 0;
}
