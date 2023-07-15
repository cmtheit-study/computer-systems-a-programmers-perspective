//
// Created by cmtheit on 23-7-13.
//

#include <stdio.h>

long try_switch(long x) {
    int val = 300;
    switch (x) {
        case 100:
            val *= 2;
            break;
        case 102:
            val <<= 2;
            val += 1;
        case 103:
            val = ~val;
            val &= val - 1;
            break;
        case 104:
        case 105:
            val /= ~val;
            break;
        default:
            val = 3000;
    }
    return val;
}

int main(int argc, char ** argv) {
    static void * switch_table[] = {&&ret, &&start};
start:
    printf("return loc: %p\n", switch_table[0]);
    printf("%ld\n", try_switch(10));
    if (argc) goto *switch_table[argc - 1];
    printf("before ret");
ret:
    return 0;
}