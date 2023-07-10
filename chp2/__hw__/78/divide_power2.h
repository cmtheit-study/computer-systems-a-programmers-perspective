//
// Created by cmtheit on 23-7-10.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_DIVIDE_POWER2_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_DIVIDE_POWER2_H

int divide_power2(int x, int k) {
    register int sign = (x >> ((sizeof(int) << 3) - 1)) & 1;
    return (((sign << k) - sign) + x) >> k;
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_DIVIDE_POWER2_H
