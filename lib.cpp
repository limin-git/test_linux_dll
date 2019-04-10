#include "lib.h"
#include <cstdlib>

int& getInstance()
{
    static int instance = 0;
    return instance;
}
