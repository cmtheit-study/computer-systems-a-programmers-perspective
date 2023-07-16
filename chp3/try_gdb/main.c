//
// Created by cmtheit on 23-7-15.
//

#include <stdio.h>

void friends(int * i, int friends) {
    printf("Hello my friends!\n");
    *i += friends;
}

int main() {
    int a = 0;
    friends(&a, 100);
    printf("goodbye, my friends %d!\n", a);
    return 0;
}