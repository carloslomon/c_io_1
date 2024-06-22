CC = gcc
CFLAGS = -g -Wall
LDFLAGS = -g

main: main.o convert.o
	$(CC) $(LDFLAGS) main.o convert.o -o main

main.o: main.c convert.h
	$(CC) -c $(CFLAGS) main.c -o main.o

convert.o: convert.c convert.h
	$(CC) -c $(CFLAGS) convert.c -o convert.o

.PHONY: clean all

clean:
	rm -rf *.o a.out core main

all: main

.PHONY: run

run: 
	./main
