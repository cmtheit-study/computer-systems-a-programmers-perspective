//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ANY_ODD_ONE_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ANY_ODD_ONE_H

#include <stdbool.h>

bool any_odd_one(unsigned x) {
    return (x & 0xcccccccc) == 0xcccccccc;
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ANY_ODD_ONE_H
