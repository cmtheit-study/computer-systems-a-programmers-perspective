//
// Created by cmtheit on 23-7-10.
//
#include "../show_bytes.h"

int main() {
    uint8_t * a = "hello world!";
    uint32_t b = 10;
    uint64_t c = INT64_MIN;
    double d = 3.15;
    show_bytes(a, 10);
    printf("\n");
    show_bytes(&b, 1);
    printf("\n");
    show_bytes(&c, sizeof (c));
    printf("\n");
    show_bytes(&d, sizeof (d));
}