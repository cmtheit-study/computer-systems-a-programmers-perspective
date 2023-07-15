	.file	"main.c"
	.text
	.globl	try_switch
	.type	try_switch, @function
try_switch:
.LFB23:
	.cfi_startproc
	endbr64
	cmpq	$103, %rdi
	je	.L5
	jg	.L3
	cmpq	$100, %rdi
	je	.L6
	cmpq	$102, %rdi
	jne	.L9
	movl	$1201, %edx
.L2:
	movl	%edx, %ecx
	notl	%ecx
	movl	$-2, %eax
	subl	%edx, %eax
	andl	%ecx, %eax
	jmp	.L4
.L9:
	movl	$3000, %eax
	jmp	.L4
.L3:
	subq	$104, %rdi
	cmpq	$1, %rdi
	ja	.L10
	movl	$0, %eax
.L4:
	cltq
	ret
.L10:
	movl	$3000, %eax
	jmp	.L4
.L5:
	movl	$300, %edx
	jmp	.L2
.L6:
	movl	$600, %eax
	jmp	.L4
	.cfi_endproc
.LFE23:
	.size	try_switch, .-try_switch
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"return loc: %p\n"
.LC1:
	.string	"%ld\n"
.LC2:
	.string	"before ret"
	.text
	.globl	main
	.type	main, @function
main:
.LFB24:
	.cfi_startproc
	endbr64
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	%edi, %ebx
.L12:
	endbr64
	leaq	.L13(%rip), %rdx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	movl	$10, %edi
	call	try_switch
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	testl	%ebx, %ebx
	je	.L14
	leal	-1(%rbx), %eax
	leaq	switch_table.0(%rip), %rdx
	cltq
	jmp	*(%rdx,%rax,8)
.L14:
	leaq	.LC2(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
.L13:
	endbr64
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE24:
	.size	main, .-main
	.section	.data.rel.ro.local,"aw"
	.align 16
	.type	switch_table.0, @object
	.size	switch_table.0, 16
switch_table.0:
	.quad	.L13
	.quad	.L12
	.ident	"GCC: (Ubuntu 11.3.0-1ubuntu1~22.04.1) 11.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
