#include "../show_bytes.h"
#include "rotate_left.h"

int main() {
    printf("%08x %08x\n", rotate_left(0x12345678, 4), rotate_left(0x12345678, 20));
}
  
