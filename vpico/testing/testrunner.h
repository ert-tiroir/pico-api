#pragma once

#ifdef VIRTUAL
#include <vpico/testing/testcase.h>
#include <string>
#include <tuple>
#include <map>

struct TestRunner {
private:
    std::map<std::pair<std::string, std::string>, TestCase*> tests; 
public:
    void create  (TestCase* test);
    void run_all ();
};
#endif