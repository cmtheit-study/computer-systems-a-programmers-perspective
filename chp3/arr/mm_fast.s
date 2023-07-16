# 失败的代码，不能跑。
    .globl asm_mm_fast
    .type  asm_mm_fast, @function

# int m         % edi
# int n         % esi
# int k         % edx
# int a[m][k]   % rcx
# int b[k][n]   % r8
# int c[m][n]   % r9
/**
for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j) {
        int tot = 0;
        for (int u = 0; u < k; ++u) {
            tot += a[i][u] * b[u][j];
        }
        c[i][j] = tot;
    }
}
return 0;
*/
asm_mm_fast:
    pushq %r12
    pushq %r13
    pushq %r14
    pushq %r15
    pushq %rbx
    pushq %rbp
    movq  %rcx,  %r10               # r10 = &a[i][0]
    movl  %edx,  %r13d
    movl  %r13d, %r14d
    shal  $2,    %r14               # r14 = k * 4
    imull %edi,  %r13d
    leaq  (%r10, %r13, 4), %r13     # r13 = r10 + m * k * 4
    leaq  (, %esi, 4),  %rax        # rax = n * 4
    .asm_mm_fast_for_i:
        movq %r8, %r11              # r11 = &b[0][i]
        leaq (%r11, %rsi, 4), %r12  # r12 = r11 + n * 4
        movl $0, %r15d              # r15: int tot = 0
        .asm_mm_fast_for_j:
            movq %r10, %rcx         # rcx = &a[i][u]
            movq %r11, %rbx         # rbx = &b[u][j]
            leaq (%rcx, %r14), %rbp
            .asm_mm_fast_for_u:
                movl  (%rcx), %edi  # edi = *rcx * *rbx
                imull (%rbx), %edi
                addl  %edi, %r15d   # tot += edi
                addq  $4,   %rcx
                addq  %rax, %rbx
                cmpq  %rcx, %rbp
                jne   .asm_mm_fast_for_u
            # 这里寄存器不够用了
            addq $4,   %r11
            cmpq %r12, %r11
            jne  .asm_mm_fast_for_j
        addq %r13, %r10
        cmpq %r10, %r13
        jne  .asm_mm_fast_for_i
    popq  %rbp
    popq  %rbx
    popq  %r15
    popq  %r14
    popq  %r13
    popq  %r12
    rep
    ret
 