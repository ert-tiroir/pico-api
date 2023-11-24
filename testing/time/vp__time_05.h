
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/stdlib.h>

struct VP__TIME_05 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        uint64_t last = 0;

        for (int i = 0; i < 256; i ++) {
            uint64_t rng     = abs(rand()) * abs(rand());
            uint64_t expects = std::max(last, rng);

            sleep_until(rng);

            if (get_absolute_time() != expects) {
                __printf("Expected sleep until to sleep until the target is reached, launched at %lld with target %lld and ended at %lld", last, rng, get_absolute_time());
                return false;
            }

            last = expects;
        }

        return true;
    }

    const char* getName     () override { return "VP__TIME_05"; }
    const char* getCategory () override { return "Time STL"; }
};

#endif
