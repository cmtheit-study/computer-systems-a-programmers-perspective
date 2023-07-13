//
// Created by cmtheit on 23-7-12.
//
#include <stdio.h>

char my_exchange(char * d, char s);

int main() {
    char m = 10;
    char before = my_exchange(&m, 30);
    printf("m before: %d, after change: %d\n", before, m);
}