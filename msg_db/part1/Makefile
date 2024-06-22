CC = gcc

INCLUDES = -I ../../linked_list_1/part1
CFLAGS = -g -Wall $(INCLUDES)

LDFLAGS = -g -L../../linked_list_1/part1
LDLIBS =  -lmylist

.PHONY: default
default: mdb-add mdb-lookup

mdb-add: mdb-add.o mdb.o
mdb-add.o: mdb.h mdb-add.c

mdb-lookup: mdb-lookup.o mdb.o
mdb-lookup.o: mdb.h mdb-lookup.c

mdb.o: mdb.h mdb.c
.PHONY: clean
clean:
	 rm -f *.o a.out core mdb-lookup mdb-add

.PHONY: all
all: clean mdb-lookup mdb-add