#pragma once

#ifdef VIRTUAL

struct TestCase {
public:
    virtual void setup () {};
    virtual bool run   () { return false; };

    virtual const char* getName     () { return ""; };
    virtual const char* getCategory () { return ""; };
};

#endif