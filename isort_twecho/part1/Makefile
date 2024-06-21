
# Default target
isort: 

.PHONY: clean
clean:
	rm -rf *.o isort core

.PHONY: run
run: 
	./isort

.PHONY: run_valgrind
run_valgrind: 
	valgrind ./isort
