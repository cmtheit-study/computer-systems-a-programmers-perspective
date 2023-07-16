//
// Created by cmtheit on 23-7-16.
//
#include <complex.h>
#include <stdio.h>

void print_complex(double complex c) {
    printf("%lf + %lfi", creal(c), cimag(c));
}

double complex minus_one(double complex c);

int main() {
    double complex a = creal(100.0) + I * cimag(3.40);
    print_complex(a);
    printf("\n");
    a = minus_one(a);
    print_complex(a);
    printf("\n");
}