#include "../show_bytes.h"
#include "shift.h"

int main() {
    int x = -0x10, k = 3;
    unsigned y = 0xff;
    printf("%d\n", sra(x, k) == x >> k);
    printf("%d\n", srl(y, k) == y >> k);
}
  
