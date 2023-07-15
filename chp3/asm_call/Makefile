asm_main:
	gcc -O1 -S main.c -o main.asm

asm_main_c:
	gcc main.s -o main
	./main
	rm main

dump:
	gcc main.c -o main
	objdump -d main
	rm ./main

obj_main:
	gcc main.c -c -o main.o
	objdump -d main.o
	rm main.o

main:
	gcc main.c -o main
	./main
	rm ./main