//
// Created by cmtheit on 23-7-10.
//

#include "../show_bytes.h"
#include "comb.h"

int main() {
    int x = 0x89ABCDEF, y = 0x76543210;
    int z = comb(x, y);
    show_bytes_ln(&z, sizeof (z));
}