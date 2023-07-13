    .globl asm_add4_sub3_mul2
    .type asm_add4_sub3_mul2, @function
 
 asm_add4_sub3_mul2:
    addb  $4, %dil
    subb  $3, %sil
    imulq %rsi, %rdi
    imulq $2, %rdi
    movb  %dil, %al
    incb  %al
    ret
