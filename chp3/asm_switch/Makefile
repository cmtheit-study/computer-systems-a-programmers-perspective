asm_main:
	gcc main.c -Og -S -o main.asm

obj_main:
	gcc -c main.c -o main.o
	objdump -d main.o
	rm ./main.o