    .globl asm_link_sum
    .type  asm_link_sum, @function
 
asm_link_sum:
    movq   $0, %rax
    testq  %rdi, %rdi
    je     .asm_link_sum_done
    .asm_link_sum_while:
        addq  8(%rdi), %rax
        movq  (%rdi), %rdi
        testq %rdi,   %rdi
        jne   .asm_link_sum_while
    .asm_link_sum_done:
        rep
        ret
 