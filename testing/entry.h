
#ifdef VIRTUAL

#include <vpico/testing/testrunner.h>

#include <testing/uart/vp__uart_xx.h>
#include <testing/time/vp__time_xx.h>

#include <testing/gpio/device/vp__dgpio_xx.h>

#ifdef TESTING

TestRunner* create_test_runner () {
    TestRunner* runner = new TestRunner();

    add_uart(runner);
    add_time(runner);

    add_dgpio(runner);

    return runner;
}
#else

TestRunner* create_test_runner () {
    return new TestRunner();
}
#endif

#endif
