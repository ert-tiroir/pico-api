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

#ifdef TESTING
#include <vector>
#include <string>

void add_to_cout_buffer (std::string buffer);
std::string get_cout_buffer ();

#define __show(...) { add_to_cout_buffer( #__VA_ARGS__ ); }
#else
#define __show(...) { __printf(__VA_ARGS__); }
#endif

#define __log(...)     { __show("[LOG] : "); __show(__VA_ARGS__); }
#define __debug(...)   { __show("[DEBUG] : "); __show(__VA_ARGS__); }
#define __warning(...) { __show("[WARNING] : "); __show(__VA_ARGS__); }
#define __danger(...)  { __show("[DANGER] : "); __show(__VA_ARGS__); throw new std::runtime_error(""); }

#define printf(...) { if (is_uart_on()) { __log(__VA_ARGS__); } else { __danger("Expected UART to be on to use printf in a pico context\n"); throw new std::runtime_error( "" ); } }

#include <vpico/time.h>

#endif
