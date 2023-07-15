    .globl asm_max
    .type asm_max, @function
 
asm_max:
    cmpq   %rsi, %rdi
    movq   %rdi, %rax
    cmovl  %rsi, %rax
    ret
