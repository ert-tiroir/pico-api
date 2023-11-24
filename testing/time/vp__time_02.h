
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/stdlib.h>

struct VP__TIME_02 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        uint64_t last = 0;

        for (int i = 0; i < 256; i ++) {
            uint64_t rng = rand();

            sleep_ms(rng);
            
            uint64_t expects = last + 1000 * rng;
            if (get_absolute_time() != expects) {
                __printf("Started sleeping at t = %lld, slept for dt = %lld ms and expected time to be %lld, but found %lld\n", last, rng, expects, get_absolute_time());
                return false;
            }
            last = expects;
        }

        return true;
    }

    const char* getName     () override { return "VP__TIME_02"; }
    const char* getCategory () override { return "Time STL"; }
};

#endif
