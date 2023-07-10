#include "../float_bits.h"
#include <math.h>
#include <stdint.h>

int main() {
    float a = 123.45f;
    printf("%d %d\n", (int)a, float_f2i(float2bits(a)));
    a = INFINITY;
    printf("%d %d\n", (int)a, float_f2i(float2bits(a)));
    a = INT32_MAX;
    printf("%d %d\n", (int)a, float_f2i(float2bits(a)));
    a = NAN;
    printf("%d %d\n", (int)a, float_f2i(float2bits(a)));
    a = bits2float(0x000fffff);
    printf("%d %d\n", (int)a, float_f2i(float2bits(a)));
    a = 0.9999;
    printf("%d %d\n", (int)a, float_f2i(float2bits(a)));
    a = 1.9999;
    printf("%d %d\n", (int)a, float_f2i(float2bits(a)));
    a = 0x7fffffff;
    printf("%d %d\n", (int)a, float_f2i(float2bits(a)));
}
  
