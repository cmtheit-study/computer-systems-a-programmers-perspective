    .globl asm_frac_while
    .type  asm_frac_while, @function
 
asm_frac_while:
    movl  $1, %eax
    testq %rdi, %rdi
    jle   .asm_frac_while_done
    .asm_frac_while_loop:
        imulq %rdi, %rax
        decq  %rdi
        testq %rdi, %rdi
        jne .asm_frac_while_loop
    .asm_frac_while_done:
        rep
        ret
 