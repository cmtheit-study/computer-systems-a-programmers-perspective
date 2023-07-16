    .globl asm_matrix_mul
    .type  asm_matrix_mul, @function

# int m         % edi
# int n         % esi
# int k         % edx
# int a[m][k]   % rcx
# int b[k][n]   % r8
# int c[m][n]   % r9
asm_matrix_mul:
    pushq %r12
    pushq %r13
    pushq %r14
    pushq %r15
    movl $0, %r10d                  # int i = 0
    .asm_matrix_mul_for_i:
        movl $0, %r11d              # int j = 0
        .asm_matrix_mul_for_j:
            movl $0, %r12d          # int tot = 0;
            movl $0, %r13d          # int u = 0
            .asm_matrix_mul_for_u:
                movl  %r10d, %r14d
                imull %edx,  %r14d
                addl  %r13d, %r14d
                movl  (%rcx, %r14, 4), %r14d
                movl  %r13d, %r15d
                imull %esi,  %r15d
                addl  %r11d, %r15d
                movl  (%r8,  %r15, 4), %r15d
                imull %r14d, %r15d
                addl  %r15d, %r12d
                incl  %r13d
                cmpl  %edx, %r13d
                jne    .asm_matrix_mul_for_u
            movl  %r10d, %r14d
            imull %esi,  %r14d
            addl  %r11d, %r14d
            movl  %r12d, (%r9, %r14, 4)
            incl  %r11d
            cmpl  %esi, %r11d
            jne   .asm_matrix_mul_for_j
        incl %r10d
        cmpl %edi, %r10d
        jne  .asm_matrix_mul_for_i
    popq  %r15
    popq  %r14
    popq  %r13
    popq  %r12
    rep
    ret
 