
#include <vpico/testing/testcase.h>

#ifdef VIRTUAL

#include <vpico/stdlib.h>

struct VP__UART_02 : public TestCase {
public:
    void setup () override {}
    bool run   () override {
        setup_default_uart();
        return is_uart_on ();
    }

    const char* getName     () override { return "VP__UART_02"; }
    const char* getCategory () override { return "Default UART"; }
};

#endif
