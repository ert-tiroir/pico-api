
#ifdef VIRTUAL

#include <vpico/testing/testrunner.h>

#include <testing/gpio/device/vp__dgpio_01.h>
#include <testing/gpio/device/vp__dgpio_02.h>
#include <testing/gpio/device/vp__dgpio_03.h>
#include <testing/gpio/device/vp__dgpio_04.h>

#include <testing/gpio/device/led/vp__dled_01.h>
#include <testing/gpio/device/led/vp__dled_02.h>

void add_dgpio (TestRunner* runner) {
    runner->create ( new VP__DGPIO_01() );
    runner->create ( new VP__DGPIO_02() );
    runner->create ( new VP__DGPIO_03() );
    runner->create ( new VP__DGPIO_04() );

    runner->create ( new VP__DLED_01() );
    runner->create ( new VP__DLED_02() );
}

#endif

