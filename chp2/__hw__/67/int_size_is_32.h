//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_INT_SIZE_IS_32_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_INT_SIZE_IS_32_H

#include <stdbool.h>
#include <limits.h>

bool int_size_is_32() {
    return INT_MAX > 0x7fff && INT_MAX == 0x7fffffff;
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_INT_SIZE_IS_32_H
