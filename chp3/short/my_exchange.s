    .globl	my_exchange
	.type	my_exchange, @function

my_exchange:
    endbr64
    movb (%rdi), %al
    movb %sil, (%rdi)
    ret
