#pragma once

#ifndef VIRTUAL
#include "pico/stdlib.h"
#include <stdio.h>
#else

#include <stdio.h>
#include <stdexcept>

const auto __printf = printf;

bool is_uart_on ();
void setup_default_uart ();

void reset_uart ();

#define __show(...) { __printf(__VA_ARGS__); }

#define __log(...)     { __printf("[LOG] : "); __show(__VA_ARGS__); }
#define __debug(...)   { __printf("[DEBUG] : "); __show(__VA_ARGS__); }
#define __warning(...) { __printf("[WARNING] : "); __show(__VA_ARGS__); }
#define __danger(...)  { __printf("[DANGER] : "); __show(__VA_ARGS__); throw new std::runtime_error(""); }

#define printf(...) { if (is_uart_on()) { __log(__VA_ARGS__); } else { __danger("Expected UART to be on to use printf in a pico context\n"); throw new std::runtime_error( "" ); } }

#include <vpico/time.h>

#endif
