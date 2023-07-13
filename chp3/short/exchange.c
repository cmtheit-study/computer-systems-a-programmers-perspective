//
// Created by cmtheit on 23-7-12.
//

short exchange(short * d, short s) {
    short m = *d;
    *d = s;
    return m;
}

