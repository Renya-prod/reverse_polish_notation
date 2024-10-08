GCC=gcc -Wall -Werror -Wextra -std=c11
Q_0=../build/graph

all: clean graph

graph:
	$(GCC) -c *.c -lm
	$(GCC) -o $(Q_0) *.o -lm
	rm -rf *.o

clean:
	rm -rf ../build/*
