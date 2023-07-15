//
// Created by cmtheit on 23-7-14.
//
#include <stdio.h>

int add(int a, int b) {
    return a & (a ^ b) + b;
}

int minus(int a, int b) {
    return add(a, b) ^ add(b, a - b);
}

int add_all(int a, int b, int c, int d, int e,
            int f, int g, int h, int i, int j) {
    return a & b ^ c | d - e + f & g | h ^ i + ~j;
}

void * test_stack() {
    register void * return_address;
    __asm__ volatile (
        "movq 24(%%rsp), %[return_address]\n"
        : [return_address] "=r" (return_address)
        :
        : "memory"
    );
    printf("return address is %p\n", return_address);
}

int main(int argc, char ** argv) {
    add_all(argc, argc + 1, argc + 2, argc + 3, argc + 4, argc + 5, argc + 6, argc + 8, argc + 10, argc - 1);
    printf("main pos is: %p\n", main);
    printf("test_stack pos is: %p\n", test_stack);
    add(argc, argc * 2);
    minus(argc, argc);
    void * next_address;
    test_stack();
    __asm__ volatile (
        "leaq (%%rip), %[next_address]\n"
        : [next_address] "=r" (next_address)
        :
        : "memory"
    );
    printf("next address is %p\n", next_address);
    return 0;
}