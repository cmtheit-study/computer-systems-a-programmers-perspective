    .globl asm_frac_w_jtm
    .type  asm_frac_w_jtm, @function
 
asm_frac_w_jtm:
    movl $1, %eax
    jmp .asm_frac_w_jtm_test
    .asm_frac_w_jtm_loop:
        imulq %rdi, %rax
        decq  %rdi
    .asm_frac_w_jtm_test:
        testq %rdi, %rdi
        jg    .asm_frac_w_jtm_loop
    rep
    ret
 