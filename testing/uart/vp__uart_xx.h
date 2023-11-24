
#ifdef VIRTUAL

#include <vpico/testing/testrunner.h>

#include <testing/uart/vp__uart_01.h>
#include <testing/uart/vp__uart_02.h>

void add_uart (TestRunner* runner) {
    runner->create( new VP__UART_01() );
    runner->create( new VP__UART_02() );
}

#endif
