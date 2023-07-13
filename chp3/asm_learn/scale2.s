    .globl asm_scale2
    .type  asm_scale2, @function

asm_scale2:
    leaq (, %rdi, 4), %rax
    leaq (%rax, %rsi, 2), %rax
    leaq 1(%rax, %rdx), %rax
    ret
