//
// Created by cmtheit on 23-7-10.
//

#include "../float_bits.h"
#include <stdint.h>

int main() {
    printf("%f %f\n", bits2float(float_i2f(10)), 10.0);
    float m = 100;
    printf("%f %f\n", bits2float(float_i2f(100)), m);
    m = INT32_MAX;
    printf("%f %f\n", bits2float(float_i2f(INT32_MAX)), m);
    m = -10;
    printf("%f %f\n", bits2float(float_i2f(-10)), m);
    m = -100;
    printf("%f %f\n", bits2float(float_i2f(-100)), m);
    m = INT32_MIN;
    printf("%f %f\n", bits2float(float_i2f(INT32_MIN)), m);
}