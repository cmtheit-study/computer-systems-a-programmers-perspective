    .globl asm_dcla
    .type  asm_dcla, @function
 
asm_dcla:
    leaq (%rsi, %rdi, 8), %r10
    .asm_dcla_for:
        vmovsd      (%rsi), %xmm8
        vcvttsd2siq %xmm8,  %r11
        movq        %r11,   (%rdx)
        addq        $8,     %rdx
        addq        $8,     %rsi
        cmpq %r10, %rsi
        jne  .asm_dcla_for
    rep
    ret
 