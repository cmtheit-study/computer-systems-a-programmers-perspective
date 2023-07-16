//
// Created by cmtheit on 23-7-15.
//
#include <stdio.h>

int try_read_unaligned(long * a);

int main() {
    long a = 0xfedcba9876543210ul;
    printf("%x\n", try_read_unaligned(&a));
}