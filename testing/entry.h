
#ifdef VIRTUAL

#include <vpico/testing/testrunner.h>

#include <testing/uart/vp__uart_xx.h>
#include <testing/time/vp__time_xx.h>

TestRunner* create_test_runner () {
    TestRunner* runner = new TestRunner();

    add_uart(runner);
    add_time(runner);

    return runner;
}

#endif
