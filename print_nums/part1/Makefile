main: main.o gcd.o prime.o 
	gcc -o -Wall -g main.o gcd.o prime.o -o main

main.o: main.c prime.h gcd.h
	gcc -c -g -Wall main.c -o main.o

prime.o: prime.c prime.h
	gcc -c -g -Wall prime.c -o prime.o

gcd.o: gcd.c gcd.h
	gcc -c -g -Wall gcd.c -o gcd.o

.PHONY: 
clean: 
	rm -f *.exe *.o *~ 
clean_all: 
	rm -f *.exe *.o *~ main
.PHONY:
run:
	./main

