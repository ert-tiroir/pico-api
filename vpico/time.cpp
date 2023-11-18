
#include <vpico/time.h>

/* This is the virtual time taken since the boot, it is assumed that
   every operation done on the micro controller takes no time */
uint64_t us_since_boot = 0;

/**************************************************************************************/
/*                                 TIME MODIFICATIONS                                 */
/**************************************************************************************/

/**
 * Sleep duration micro seconds, equivalent to adding the duration to the virtual
 * time.
 */
void sleep_us (uint64_t duration) { us_since_boot += duration; }

/**
 * Sleep duration milliseconds, equivalent to adding the duration in micro seconds
 * to the virtual time since boot.
*/
void sleep_ms (uint32_t duration) { sleep_us(((uint64_t) duration) * 1000u); }

/**
 * Wait for the time to reach a milestone, equivalent to setting the virtual time to the
 * target if it is less than or equal
 */
void sleep_until (uint64_t target) {
    if (target < us_since_boot) us_since_boot = target;
}

/**************************************************************************************/
/*                                    TIME QUERIES                                    */
/**************************************************************************************/

/**
 * Convert microseconds to milliseconds
*/
uint32_t us_to_ms (uint64_t duration_us) {
    return duration_us / 1000u;
}

/**
 * Get the absolute time of the micro controller, equivalent to getting the virtual time
 */
uint64_t get_absolute_time () {
    return us_since_boot;
}
