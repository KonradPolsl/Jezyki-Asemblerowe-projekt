#include <stdint.h>

uint64_t MyProc1C(uint64_t a, uint64_t b)
{
    uint64_t suma = a + b;

    if (suma >= a)
        return (~suma) + 1;

    suma = (suma >> 1) | (suma << 63);
    return suma * suma;
}