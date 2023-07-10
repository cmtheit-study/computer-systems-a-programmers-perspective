//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_REPLACE_BYTES_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_REPLACE_BYTES_H
#include <stdint.h>

unsigned replace_bytes(unsigned x, int i, unsigned char b) {
    if (0 <= i && i <= 3) {
        ((uint8_t*)&x)[i] = b;
        return x;
    } else {
        return x;
    }
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_REPLACE_BYTES_H
