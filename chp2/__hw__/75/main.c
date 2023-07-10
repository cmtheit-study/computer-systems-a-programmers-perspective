#include "../show_bytes.h"
#include "high_prod.h"

int main() {
    printf("%08x %08x\n", unsigned_high_prod(1, 2), unsigned_high_prod(UINT32_MAX, 100));
}
  
