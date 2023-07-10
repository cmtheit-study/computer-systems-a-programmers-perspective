//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_COMB_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_COMB_H

int comb(int x, int y) {
    return (y & ~0xff) | (x & 0xff);
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_COMB_H
