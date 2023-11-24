
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/stdlib.h>

struct VP__TIME_01 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        return get_absolute_time() == 0;
    }

    const char* getName     () override { return "VP__TIME_01"; }
    const char* getCategory () override { return "Time STL"; }
};

#endif
