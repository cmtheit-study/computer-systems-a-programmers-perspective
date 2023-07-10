#include "../show_bytes.h"
#include "lower_one_mask.h"

int main() {
    printf("%08x %08x %08x\n", lower_one_mask(6), lower_one_mask(17), lower_one_mask(32));
}
  
