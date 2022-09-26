CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: BinaryTree.h BinaryTree.cpp main.cpp
	$(CC) $(CFLAGS) -o main BinaryTree.cpp main.cpp

clean:
	rm -rf main
	rm -rf *.o
