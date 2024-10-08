GCC=gcc -Wall -Werror -Wextra -std=c11
Q_0=rpn

all: clean graph

graph:
	$(GCC) -c *.c -lm
	$(GCC) -o $(Q_0) *.o -lm

clean:
	rm -rf *.o
