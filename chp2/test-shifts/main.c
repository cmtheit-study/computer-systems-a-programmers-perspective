#include <stdio.h>
#define VAL 0xcccccc

int main() {
    unsigned val = 0xfedcba98;
    printf("%08x %08x %08x\n", val << 32, val >> 36, val >> 40);
    val = VAL;
    printf("%08x %08x %08x %08x\n", val, val << 32, val >> 36, val >> 40);
    printf("%08x %08x %08x %08x\n", VAL, VAL << 32, VAL >> 36, VAL >> 40);
    int lval = VAL << 32;
    int aval = VAL >> 36;
    int uval = (unsigned)VAL >> 40;
    printf("%08x %08x %08x\n", lval, aval, uval);
}
  
