//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_HIGH_PROD_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_HIGH_PROD_H

int signed_high_prod(int x, int y) {
    return (long)(unsigned ) x * y >> (sizeof(x) << 3);
}

unsigned unsigned_high_prod(unsigned x, unsigned y) {
    return signed_high_prod(x, y);
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_HIGH_PROD_H
