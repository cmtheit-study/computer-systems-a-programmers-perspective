    .globl asm_arith
    .type  asm_arith, @function
 
asm_arith:
    xorq  %rdi, %rsi
    imulq $48, %rdx
    andq  $0x0f0f0f0f, %rsi
    subq  %rsi, %rdx
    movq  %rdx, %rax
    ret
