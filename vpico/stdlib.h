
#define VIRTUAL

#ifndef VIRTUAL
#include "pico/stdlib.h"
#include <stdio.h>
#else

#include <stdio.h>
#include <stdexcept>

const auto __printf = printf;

bool is_uart_on ();
void setup_default_uart ();

#define printf(...) { if (is_uart_on()) { __printf(__VA_ARGS__); } else { __printf("ERROR, expected UART to be on\n"); throw new std::runtime_error( "" ); } }

#include <vpico/time.h>

#endif
