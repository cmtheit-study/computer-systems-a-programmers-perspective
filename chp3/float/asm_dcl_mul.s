    .globl asm_dcl_mul
    .type  asm_dcl_mul, @function
 
asm_dcl_mul:
    vcvttsd2siq %xmm0, %rax
    vcvttss2siq %xmm1, %r10
    imulq       %r10,  %rax
    rep
    ret
 