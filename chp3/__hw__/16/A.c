//
// Created by cmtheit on 23-7-13.
//

void A_cond(long a, long * p) {
    if (p == 0)
        goto ret;
    if (*p - a >= 0)
        goto ret;
    *p = a;
    ret:
    return;
}

