    .globl find_range
    .type  find_range, @function
 
find_range:
    vxorps   %xmm1, %xmm1, %xmm1
    vucomisd %xmm1, %xmm0
    jp  .find_range_nan
    ja  .find_range_positive
    je  .find_range_zero
    movl $0, %eax
    ret
    .find_range_zero:
        movl $1, %eax
        ret
    .find_range_positive:
        movl $2, %eax
        ret
    .find_range_nan:
        movl $3, %eax
        ret
 