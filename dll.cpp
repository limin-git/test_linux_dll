#include "lib.h"

extern "C"
{
    int get();
    void set(int);
}

int get()
{
    return getInstance();
}

void set(int x)
{
    getInstance() = x;
}
