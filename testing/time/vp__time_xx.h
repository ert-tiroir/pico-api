
#ifdef VIRTUAL

#include <vpico/testing/testrunner.h>

#include <testing/time/vp__time_01.h>
#include <testing/time/vp__time_02.h>
#include <testing/time/vp__time_03.h>
#include <testing/time/vp__time_04.h>
#include <testing/time/vp__time_05.h>

void add_time (TestRunner* runner) {
    runner->create ( new VP__TIME_01() );
    runner->create ( new VP__TIME_02() );
    runner->create ( new VP__TIME_03() );
    runner->create ( new VP__TIME_04() );
    runner->create ( new VP__TIME_05() );
}

#endif

