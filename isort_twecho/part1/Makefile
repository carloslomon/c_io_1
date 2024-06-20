CC = gcc
CFLAGS = -g -Wall 
LDFLAGS = -g 
isort:

.PHONY: clean
	clean: 
		rm -rf *.o a.out core main
.PHONY: 
	run: 
		./isort
	run_valgrind:
		valgrind ./isort