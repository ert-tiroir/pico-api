
#include <vpico/time.h>

#ifdef VIRTUAL

#ifdef REALTIME
#include <chrono>
#include <thread>

void __sleep_microseconds (uint64_t duration) {
    std::this_thread::sleep_for(std::chrono::microseconds(duration));
}
#else
void __sleep_microseconds (uint64_t duration) {}
#endif

/* This is the virtual time taken since the boot, it is assumed that
   every operation done on the micro controller takes no time */
uint64_t us_since_boot = 0;

/**************************************************************************************/
/*                                 TIME MODIFICATIONS                                 */
/**************************************************************************************/

/**
 * Sleep duration micro seconds, equivalent to adding the duration to the virtual
 * time, and if the vpico is used for realtime application sleep during the duration.
 */
void sleep_us (uint64_t duration) {
    __sleep_microseconds(duration);
    us_since_boot += duration;
}

/**
 * Sleep duration milliseconds, equivalent to adding the duration in micro seconds
 * to the virtual time since boot.
*/
void sleep_ms (uint32_t duration) {
    sleep_us(((uint64_t) duration) * 1000u);
}

/**
 * Wait for the time to reach a milestone, equivalent to setting the virtual time to the
 * target if it is less than or equal, and if the vpico is used for realtime application,
 * sleep through the time.
 */
void sleep_until (uint64_t target) {
    if (target < us_since_boot) {
        __sleep_microseconds(us_since_boot - target);

        us_since_boot = target;
    }
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
#endif
