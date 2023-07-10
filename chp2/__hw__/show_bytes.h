//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHOW_BYTES_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHOW_BYTES_H

#include <stdio.h>
#include <stdint.h>

void show_bytes(void * p, size_t size) {
    for (register size_t i = 0; i < size; ++i) {
        printf("%02x ", ((uint8_t *)p)[i]);
    }
}

void show_bytes_ln(void * p, size_t size) {
    show_bytes(p, size);
    printf("\n");
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHOW_BYTES_H
