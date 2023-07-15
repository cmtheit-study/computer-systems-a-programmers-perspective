    .globl asm_rfact
    .type  asm_rfact, @function
 
asm_rfact:
    pushq %rbx
    movl  %edi, %ebx
    cmpl  $0, %ebx
    jle   .asm_rfact_not_recurse
    .asm_rfact_recurse:
        subl   $1, %edi
        call   asm_rfact
        imull  %ebx, %eax
        jmp    .asm_rfact_done
    .asm_rfact_not_recurse:
        movl  $1, %eax
        jmp   .asm_rfact_done
    .asm_rfact_done:
        popq  %rbx
        ret
 