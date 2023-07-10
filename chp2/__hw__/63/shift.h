//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHIFT_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHIFT_H

unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    return xsra & ((1u << ((sizeof (int) * 8) - k)) - 1);
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    return xsrl | (((1u << k) - 1) << (sizeof(int) * 8 - k));
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_SHIFT_H
