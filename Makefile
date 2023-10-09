CHECK = -c -Wall -Werror -Wextra
all: graph

cl_fr:
	clang-format -n  *.c *.h

cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h

graph: calculate.o graph.o input_valid.o pol_notat.o printing.o stack.o
	gcc -o ../build/graph calculate.o graph.o input_valid.o pol_notat.o printing.o stack.o

calculate.o: calculate.c
	gcc $(CHECK) -o calculate.o calculate.c

graph.o: graph.c
	gcc $(CHECK) -o graph.o graph.c

input_valid.o: input_valid.c
	gcc $(CHECK) -o input_valid.o input_valid.c

pol_notat.o: pol_notat.c
	gcc $(CHECK) -o pol_notat.o pol_notat.c

printing.o: printing.c
	gcc $(CHECK) -o printing.o printing.c

stack.o: stack.c
	gcc $(CHECK) -o stack.o stack.c

clean:
	rm -rf *.o ../build/graph

rebuild:
	make clean && make
