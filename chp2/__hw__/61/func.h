//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FUNC_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FUNC_H
#include <stdbool.h>
#include <stdint.h>
#include <limits.h>

bool A__all_bits_one(int x) {
    return !~x;
}

bool B__all_bits_zero(int x) {
    return !(x ^ 0);
}

bool C__low_byte_all_one(int x) {
    return !(~x & 0xff);
}

bool D__high_byte_all_zero(int x) {
    return !((~INT_MAX >> 8) & ~x);
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FUNC_H
