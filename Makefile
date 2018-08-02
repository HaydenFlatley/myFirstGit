shell: main.o calc.o dump.o
	cc main.p calc.o dump.o -o all
main.o: main.c calc.c dump.c common.h
	cc -c main.c
calc.o: calc.c common.h
	cc -c calc.c
dump.o: dump.c commo.h
	cc -c dump.c