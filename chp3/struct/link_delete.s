    .globl asm_link_delete
    .type  asm_link_delete, @function
 
asm_link_delete:
    jmp  .asm_link_delete_while_test
    .asm_link_delete_while:
        decq  %rsi
        movq  (%rdi), %rdi
        .asm_link_delete_while_test:
            testq  %rsi, %rsi
            je     .asm_link_delete_while_done
            movq   (%rdi), %r10
            testq  %r10,   %r10
            jne    .asm_link_delete_while
    .asm_link_delete_while_done:
    movq  (%rdi), %r10
    testq %r10,   %r10
    je    .asm_link_delete_done
    movq  (%r10), %r10
    movq  %r10,   (%rdi)
    .asm_link_delete_done:
        rep
        ret
 