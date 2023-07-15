//
// Created by cmtheit on 23-7-13.
//

#ifndef COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FLOW_H
#define COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FLOW_H
#define ASM_DEFINE(name, ...) \
long asm_##name(__VA_ARGS__);  \
long name(__VA_ARGS__)                              \


ASM_DEFINE(nabs, long x) {
    if (x > 0) {
        return -x;
    } else {
        return x;
    }
}

ASM_DEFINE(max, long x, long y) {
    return x > y ? x : y;
}

ASM_DEFINE(frac, long f) {
    long v = 1;
    do {
        v *= f;
        f--;
    } while (f >= 1);
    return v;
}

ASM_DEFINE(frac_while, long f) {
    long v = 1;
    while (f > 0) {
        v *= f;
        f--;
    }
    return v;
}

ASM_DEFINE(frac_w_jtm, long f) {
    long v = 1;
    while (f > 0) {
        v *= f;
        f--;
    }
    return v;
}

ASM_DEFINE(frac_for, long f) {
    long v = 1;
    for (int i = 2; i <= f; ++i) {
        v *= i;
    }
    return v;
}

#endif //COMPUTER_SYSTEMS_A_PROGRAMMERS_PERSPECTIVE_FLOW_H
