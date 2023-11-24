
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/stdlib.h>

struct VP__TIME_04 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        uint64_t last = 0;

        for (int i = 0; i < 256; i ++) {
            uint64_t rng = rand() * rand() % ((uint64_t) 1e13);

            uint32_t expects = rng / ((uint64_t) 1000);

            if (us_to_ms(rng) != expects) {
                __printf("Error in us_to_ms, expected %d for input %lld, got %d\n", expects, rng, us_to_ms(rng));
                return false;
            }
        }

        return true;
    }

    const char* getName     () override { return "VP__TIME_04"; }
    const char* getCategory () override { return "Time STL"; }
};

#endif
