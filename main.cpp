#include <iostream>
#include "lib.h"
#include <dlfcn.h>
#include <cstdlib>

int dll_get(void* dll)
{
    int (*get)() = dlsym(dll, "get");
    return get();
}

void dll_set(void* dll, int x)
{
    void (*set)(int) = dlsym(dll, "set");
    set(x);
}

void printAll(void* dll1, void* dll2)
{
    std::cout << "main: " << getInstance() << std::endl;
    std::cout << "dll1: " << dll_get(dll1) << std::endl;
    std::cout << "dll2: " << dll_get(dll2) << std::endl;
    std::cout << "--------------------------------------" << std::endl;
}

void* open_dll(const char* name, int flag = RTLD_LAZY)
{
    void* dll = dlopen(name, flag);

    if (dll == NULL)
    {
        std::cout << "error: " << dlerror() << std::endl;
    }

    return dll;
}

int main(int argc, char* argv[])
{
    getInstance();

    void* dll1 = open_dll("libdll1.so", RTLD_LAZY);
    void* dll2 = open_dll("libdll2.so", RTLD_LAZY);

    if (!(dll1 && dll2))
    {
        exit(0);
    }

    getInstance() = 999;
    printAll(dll1, dll2);

    dll_set(dll1, 1);
    printAll(dll1, dll2);

    dll_set(dll2, 2);
    printAll(dll1, dll2);

    std::cout << "hello, world!" << std::endl;
    return 0;
}
