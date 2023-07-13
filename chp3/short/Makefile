c:
	gcc exchange.c -Og -S

o:
	gcc exchange.s -Og -c

my_o:
	gcc my_exchange.s -Og -c

call_my:
	gcc call_myo.c my_exchange.s -o call_myo
	./call_myo
	rm ./call_myo