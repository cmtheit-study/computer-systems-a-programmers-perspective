    .globl asm_shl1_add10_shr2
    .type asm_shl1_add10_shr2, @function
 
asm_shl1_add10_shr2:
    sall $1, %edi
    addl $10, %edi
    imul $2, %esi
    movb %sil, %cl
    sarl %cl, %edi
    movl %edi, %eax
    ret
