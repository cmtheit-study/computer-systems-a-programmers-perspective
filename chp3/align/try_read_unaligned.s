    .globl try_read_unaligned
    .type  try_read_unaligned, @function
 
try_read_unaligned:
    movl 1(%rdi), %eax
    ret
 