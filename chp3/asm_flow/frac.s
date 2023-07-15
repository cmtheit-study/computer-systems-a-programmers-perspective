    .globl asm_frac
    .type  asm_frac, @function
 
asm_frac:
    movq $1, %rax
    .asm_frac_loop:
        imulq %rdi, %rax
        decq  %rdi
        cmpq  $1, %rdi
        jge   .asm_frac_loop
    ret
 