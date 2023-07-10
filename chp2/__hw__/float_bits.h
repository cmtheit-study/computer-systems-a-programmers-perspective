//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FLOAT_BITS_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FLOAT_BITS_H
#include <stdio.h>

#define FLOAT_BITS_SIGN_MASK 0x80000000
#define FLOAT_BITS_SIGN_OFF 31
#define FLOAT_BITS_EXTRACT_SIGN(f) (f & FLOAT_BITS_SIGN_MASK)
#define FLOAT_BITS_SIGN(f) (FLOAT_BITS_EXTRACT_SIGN(f) >> FLOAT_BITS_SIGN_OFF)
#define FLOAT_BITS_SIGN_SET(f, sign) (f = f & ~FLOAT_BITS_SIGN_MASK | (sign << FLOAT_BITS_SIGN_OFF))

#define FLOAT_BITS_EXP_MASK 0x7f800000
#define FLOAT_BITS_EXP_OFF 23
#define FLOAT_BITS_EXTRACT_EXP(f) (f & FLOAT_BITS_EXP_MASK)
#define FLOAT_BITS_EXP(f) (FLOAT_BITS_EXTRACT_EXP(f) >> FLOAT_BITS_EXP_OFF)
#define FLOAT_BITS_EXP_SET(f, exp) (f = f & ~FLOAT_BITS_EXP_MASK | (exp << FLOAT_BITS_EXP_OFF))

#define FLOAT_BITS_FRAC_MASK 0x007fffff
#define FLOAT_BITS_FRAC_OFF 0
#define FLOAT_BITS_EXTRACT_FRAC(f) (f & FLOAT_BITS_FRAC_MASK)
#define FLOAT_BITS_FRAC(f) (FLOAT_BITS_EXTRACT_FRAC(f) >> FLOAT_BITS_FRAC_OFF)
#define FLOAT_BITS_FRAC_SET(f, frac) (f = f & ~FLOAT_BITS_FRAC_MASK | (frac << FLOAT_BITS_FRAC_OFF))

typedef unsigned float_bits;

float bits2float(float_bits f) {
    return *(float *) &f;
}

float_bits float2bits(float f) {
    return *(float_bits *) &f;
}

float_bits float_negate(float_bits f) {
    return f ^ FLOAT_BITS_SIGN_MASK;
}

float_bits float_absval(float_bits f) {
    if (FLOAT_BITS_EXTRACT_EXP(f) == FLOAT_BITS_EXP_MASK && FLOAT_BITS_EXTRACT_FRAC(f)) {
        return f;
    } else {
        return f & ~FLOAT_BITS_SIGN_MASK;
    }
}

float_bits float_twice(float_bits f) {
    if (FLOAT_BITS_EXTRACT_EXP(f) != FLOAT_BITS_EXP_MASK) {
        register unsigned exp = FLOAT_BITS_EXP(f);
        if (exp != 0) {
            exp++;
            FLOAT_BITS_EXP_SET(f, exp);
        } else {
            register unsigned frac = FLOAT_BITS_FRAC(f);
            frac <<= 1;
            FLOAT_BITS_FRAC_SET(f, frac);
            if ((f >> (FLOAT_BITS_EXP_OFF - 1)) & 1) {
                exp++;
                FLOAT_BITS_EXP_SET(f, exp);
            }
        }
    }
    return f;
}

float_bits float_half(float_bits f) {
    if (FLOAT_BITS_EXTRACT_EXP(f) != FLOAT_BITS_EXP_MASK) {
        register unsigned exp = FLOAT_BITS_EXP(f);
        register unsigned frac = FLOAT_BITS_FRAC(f);
        if (exp != 0) {
            exp--;
            FLOAT_BITS_EXP_SET(f, exp);
            if (exp == 0) {
                frac >>= 1;
                frac |= 1 << (FLOAT_BITS_EXP_OFF - 1);
            }
        } else {
            frac >>= 1;
        }
        FLOAT_BITS_FRAC_SET(f, frac);
    }
    return f;
}

int float_f2i(float_bits f) {
    register int exp = FLOAT_BITS_EXP(f) - 127;
    register int frac = FLOAT_BITS_FRAC(f) | (1 << FLOAT_BITS_EXP_OFF);
    register int sign = FLOAT_BITS_SIGN(f);
    if (exp >= (int)(sizeof(int) << 3) - 1) {
        return 0x80000000;
    } else if (exp < 0) {
        return 0;
    } else if (exp > FLOAT_BITS_EXP_OFF) {
        frac <<= exp - FLOAT_BITS_EXP_OFF;
    } else {
        frac >>= FLOAT_BITS_EXP_OFF - exp;
    }
    return sign ? ~frac + 1 : frac;
}

float_bits float_i2f(int i) {
    if (!i) return 0;
    unsigned u = i;
    float_bits fb = 0;
    register unsigned exp = FLOAT_BITS_EXP_MASK >> (FLOAT_BITS_EXP_OFF + 1);
    register int sign = FLOAT_BITS_SIGN(u);
    if (sign) {
        u = ~u + 1;
    }
    FLOAT_BITS_SIGN_SET(fb, sign);
    for (register int j = 0; j < 32; ++j) {
        if ((u << j) & FLOAT_BITS_SIGN_MASK) {
            exp += 32 - j - 1;
            u = u << j;
            unsigned half = 1 << (32 - FLOAT_BITS_EXP_OFF);
            unsigned overflowed = u & ((half << 1) - 1);
            if (overflowed > half || overflowed == half && u & (half << 1)) {
                // 向偶数方向舍入
                u += half >> 1;
                if (!(u & FLOAT_BITS_SIGN_MASK)) {
                    // 说明进了一位
                    exp ++;
                    u >>= 1;
                }
            }
            u = u << 1 >> (32 - FLOAT_BITS_EXP_OFF);
            break;
        }
    }
    FLOAT_BITS_EXP_SET(fb, exp);
    FLOAT_BITS_FRAC_SET(fb, u);
    return fb;
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FLOAT_BITS_H
