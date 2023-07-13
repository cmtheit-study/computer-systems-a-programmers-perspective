    .globl asm_uremdiv
    .type  asm_uremdiv, @function
 
asm_uremdiv:
    movq %rdi, %rax
    movq %rdx, %r8
    movq $0, %rdx
    divq %rsi
    movq %rax, (%r8)
    movq %rdx, (%rcx)
    movq $0, %rax
    ret
