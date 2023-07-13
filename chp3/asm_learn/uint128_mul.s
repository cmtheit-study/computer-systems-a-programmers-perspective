    .globl asm_uint128_mul
    .type asm_uint128_mul, @function
 
asm_uint128_mul:
    movq %rsi, %rax
    mulq %rdx
    movq %rax, (%rdi)
    movq %rdx, 8(%rdi)
    xorq %rax, %rax
    ret
