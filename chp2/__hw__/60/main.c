#include "../show_bytes.h"
#include "replace_bytes.h"

int main() {
    unsigned a = replace_bytes(0x12345678, 2, 0xAB);
    show_bytes_ln(&a, sizeof (a));
    a = replace_bytes(0x12345678, 0, 0xAB);
    show_bytes_ln(&a, sizeof(a));
}
  
