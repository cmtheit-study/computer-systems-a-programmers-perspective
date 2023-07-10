//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ROTATE_LEFT_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ROTATE_LEFT_H

unsigned rotate_left(unsigned x, int n) {
    return (x << n) | (x >> (sizeof(int) * 8 - n));
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_ROTATE_LEFT_H
