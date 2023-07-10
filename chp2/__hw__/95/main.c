#include "../float_bits.h"
#include <math.h>

int main() {
    float denom = bits2float(0x00ffffff);
    printf("%u\n%.50f\n", float2bits(denom), denom);
    printf("%.50f\n%.50f\n", denom / 2, bits2float(float_half(float2bits(denom))));
    float nom = 0.139;
    printf("%.5f\n%.5f\n", nom / 2, bits2float(float_half(float2bits(nom))));
    nom = -3.14;
    printf("%.5f\n%.5f\n", nom / 2, bits2float(float_half(float2bits(nom))));
    nom = 0.0;
    printf("%.5f\n%.5f\n", nom / 2, bits2float(float_half(float2bits(nom))));
    nom = INFINITY;
    printf("%.5f\n%.5f\n", nom / 2, bits2float(float_half(float2bits(nom))));
    nom = NAN;
    printf("%.5f\n%.5f\n", nom / 2, bits2float(float_half(float2bits(nom))));
}
  
