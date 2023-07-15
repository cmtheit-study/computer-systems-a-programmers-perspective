    .globl asm_nabs
    .type asm_nabs, @function
 
asm_nabs:
    cmpq $0, %rdi
    jge  .greater_than_zero
    movq %rdi, %rax
    jmp .done
.greater_than_zero:
    movq $0, %rax
    subq %rdi, %rax
    jmp .done
.done:
    rep
    ret
