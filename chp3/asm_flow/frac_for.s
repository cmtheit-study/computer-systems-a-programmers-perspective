    .globl asm_frac_for
    .type  asm_frac_for, @function
 
asm_frac_for:
    movl $1, %eax
    movq $2, %r8
    jmp .asm_frac_for_test
    .asm_frac_for_loop:
        imulq %r8, %rax
        incq  %r8
    .asm_frac_for_test:
        cmpq %r8, %rdi
        jge  .asm_frac_for_loop
    rep
    ret
 