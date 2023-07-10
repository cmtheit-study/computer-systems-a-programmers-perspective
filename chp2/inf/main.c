//
// Created by cmtheit on 23-7-9.
//
#include <stdio.h>
#include <math.h>
#include <stdint.h>

#define MY_INF (1.0 / 0.0)
#define MY_NE_INF (-1.0 / 0.0)

int main() {
    printf("%lf %lf %lf\n", INFINITY, MY_INF, MY_NE_INF);
    double bigger =(INT32_MAX >> 2) * 1000.0 ;
    printf("%lf %lf %x %d\n", INFINITY, bigger, (int)bigger, (INFINITY > 0));
}