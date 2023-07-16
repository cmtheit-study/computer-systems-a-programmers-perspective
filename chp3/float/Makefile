test1:
	gcc test1.c asm_dcl_mul.s asm_dcla.s -std=c99 -o test1
	./test1
	rm ./test1

test1_asm:
	gcc test1.c -Og -S -mavx2 -o test1.asm

test1_dump:
	gcc test1.c -c -o test1.o
	objdump -d test1.o
	rm test1.o