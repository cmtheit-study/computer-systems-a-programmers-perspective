//
// Created by cmtheit on 23-7-12.
//

long mult2(long, long);

void multstore(long x, long y, long * dest) {
    long t = mult2(x, y);
    *dest = t;
}