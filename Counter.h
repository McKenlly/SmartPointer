#ifndef COUNTER
#define COUNTER

#include <iostream>
#include <stdlib.h>

class Counter
{
private:
    size_t count;
public:
    Counter();
    void AddRef();
    size_t Release();
    virtual ~Counter() = default;
};

#endif