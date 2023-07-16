    .globl minus_one
    .type  minus_one, @function
 
minus_one:
    movl        $1, %r10d
    vcvtsi2sdq  %r10, %xmm8, %xmm8
    vsubsd      %xmm8, %xmm0, %xmm0
    vsubsd      %xmm8, %xmm1, %xmm1
    rep
    ret

