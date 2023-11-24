
#include <testing/entry.h>
#include <iostream>

int main () {
    #ifdef VIRTUAL
    TestRunner* runner = create_test_runner();
    runner->run_all();
    #endif

    return 0;
}
