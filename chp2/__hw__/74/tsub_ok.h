//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_TSUB_OK_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_TSUB_OK_H
#include <stdbool.h>
#include <limits.h>

bool tsub_ok(int x, int y) {
    return !((x ^ y) & INT_MIN && ((x ^ (x - y)) & INT_MIN));
}
#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_TSUB_OK_H
