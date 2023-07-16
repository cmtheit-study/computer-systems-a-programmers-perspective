//
// Created by cmtheit on 23-7-16.
//

#include <stdio.h>
#include <math.h>

typedef enum {NEG, ZERO, POS, NaN} tp;

tp find_range(double f);

void test(double f) {
    printf("双精度数 %lf 是", f);
    switch (find_range(f)) {
        case NEG:
            printf("负数");
            break;
        case ZERO:
            printf("零");
            break;
        case POS:
            printf("正数");
            break;
        case NaN:
            printf("NaN");
            break;
    }
    printf("\n");
}

int main() {
    test(INFINITY);
    test(1.0);
    test(0.0);
    test(-1.3);
    test(-INFINITY);
    test(NAN);
}