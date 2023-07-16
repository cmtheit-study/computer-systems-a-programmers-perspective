//
// Created by cmtheit on 23-7-16.
//
#include <alloca.h>

int test(int n) {
    char * a = alloca(n * sizeof(char));
    for (int i = 0; i < n; ++i) {
        a[i] = (char)i;
    }
    return 0;
}