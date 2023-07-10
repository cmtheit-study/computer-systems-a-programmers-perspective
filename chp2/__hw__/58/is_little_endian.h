//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_IS_LITTLE_ENDIAN_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_IS_LITTLE_ENDIAN_H
#include <stdbool.h>
#include <stdint.h>

bool is_little_endian() {
    uint16_t a = 1;
    return *(uint8_t*)&a & 1;
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_IS_LITTLE_ENDIAN_H
