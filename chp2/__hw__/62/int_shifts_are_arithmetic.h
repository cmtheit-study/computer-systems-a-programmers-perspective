//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_INT_SHIFTS_ARE_ARITHMETIC_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_INT_SHIFTS_ARE_ARITHMETIC_H
#include <stdbool.h>

bool int_shifts_are_arithmetic() {
    return !~(-1 >> 1);
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_INT_SHIFTS_ARE_ARITHMETIC_H
