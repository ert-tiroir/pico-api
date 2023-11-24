
#include <vpico/testing/testrunner.h>

#ifdef VIRTUAL

#include <vpico/stdlib.h>
#include <vpico/device/gpiodevice.h>
#include <vpico/hardware/gpio.h>

#include <iostream>
#include <vector>

void reset () {
    reset_uart();
    reset_time();
    reset_gpio_devices();
    reset_gpio();
}

void TestRunner::create (TestCase* test) {
    std::string cate = test->getCategory();
    std::string name = test->getName();

    this->tests.insert({ { cate, name }, test });
}

void TestRunner::run_all () {
    std::vector<bool> resultStates;
    for (const auto &data : tests) {
        std::string category = data.first.first;
        std::string name     = data.first.second;

        __printf( "=== %s :: %s ===\n", category.c_str(), name.c_str() );
        
        reset();
        data.second->setup();
        bool result = data.second->run();

        resultStates.push_back(result);

        __printf("\n");
    }

    std::string lcat = ""; int i = 0;
    for (const auto &data : tests) {
        std::string category = data.first.first;
        std::string name     = data.first.second;

        if (lcat != category) {
            lcat = category;

            __printf("Result for the category '%s'\n", category.c_str());
        }

        __printf("    Test Case '%s' : %s\n", name.c_str(), resultStates[i ++] ? "\033[1;32mOK\033[0m" : "\033[1;31mWRONG ANSWER\033[0m");
    }
}

#endif