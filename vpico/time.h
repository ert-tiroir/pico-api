
#include <vpico/const.h>

#ifdef VIRTUAL
#include <cstdint>

void sleep_us (uint64_t duration);
void sleep_ms (uint32_t duration);
void sleep_until (uint64_t time);

uint32_t us_to_ms (uint64_t us);
uint64_t get_absolute_time ();
#else
#include <pico/time.h>
#endif