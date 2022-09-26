CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: DoublyLinkedList.h DoublyLinkedList.cpp main.cpp
	$(CC) $(CFLAGS) -o main DoublyLinkedList.cpp main.cpp

clean:
	rm -rf main
	rm -rf *.o
