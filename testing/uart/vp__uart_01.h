
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/stdlib.h>

struct VP__UART_01 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        return !is_uart_on () == false;
    }

    const char* getName     () override { return "VP__UART_01"; }
    const char* getCategory () override { return "Default UART"; }
};

#endif
