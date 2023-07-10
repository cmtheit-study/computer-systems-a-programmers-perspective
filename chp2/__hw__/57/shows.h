//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHOWS_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHOWS_H

#include "../show_bytes.h"

void show_short(short s) {
    show_bytes(&s, sizeof (s));
}

void show_long(long l) {
    show_bytes(&l, sizeof (l));
}

void show_double(double d) {
    show_bytes(&d, sizeof (d));
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHOWS_H
