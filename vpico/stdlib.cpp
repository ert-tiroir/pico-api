
#include <vpico/stdlib.h>

bool uart_on = false;

bool is_uart_on () {
    return uart_on;
}

/**
 * Setup UART (communication with main computer for printf / scanf)
 * 
 * In the case of the virtual pico api, this enables the virtual implementation of printf / scanf
 */
void setup_default_uart () {
    uart_on = true;
    
    return ;
}

void reset_uart () {
    uart_on = false;
}
