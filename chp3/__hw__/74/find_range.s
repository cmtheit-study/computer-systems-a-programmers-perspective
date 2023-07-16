    .globl find_range
    .type  find_range, @function
 
find_range:
    pushq   %r12
    movl    $0, %eax
    movl    $1, %r10d
    movl    $2, %r11d
    movl    $3, %r12d
    vxorps   %xmm1, %xmm1, %xmm1
    vucomisd %xmm1, %xmm0
    cmove   %r10d, %eax
    cmova   %r11d, %eax
    cmovp   %r12d, %eax
    popq    %r12
    ret
