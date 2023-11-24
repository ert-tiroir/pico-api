
#ifdef VIRTUAL

#include <vpico/testing/testrunner.h>

#include <testing/uart/vp__uart_xx.h>

TestRunner* create_test_runner () {
    TestRunner* runner = new TestRunner();

    add_uart(runner);

    return runner;
}

#endif
