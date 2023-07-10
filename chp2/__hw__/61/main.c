#include "../show_bytes.h"
#include "func.h"

int main() {
    printf("%d %d\n", A__all_bits_one(~0), A__all_bits_one(1));
    printf("%d %d\n", B__all_bits_zero(0), B__all_bits_zero(1));
    printf("%d %d\n", C__low_byte_all_one(0xff), C__low_byte_all_one(1));
    printf("%d %d\n", D__high_byte_all_zero(-100), D__high_byte_all_zero(32));
}
  
