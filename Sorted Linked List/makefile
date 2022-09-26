CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++14 $(DEBUG) -O0 -pedantic-errors
LFLAGS = -Wall $(DEBUG)

main: ItemType.h ListNode.h SortedLinkedList.h main.cpp ItemType.cpp SortedLinkedList.cpp
	$(CC) $(CFLAGS) -o main main.cpp ItemType.cpp SortedLinkedList.cpp

itemtype: ItemType.h ItemType.cpp
	$(CC) $(CFLAGS) -o ItemType ItemType.h ItemType.cpp

sortedlinkedlist: SortedLinkedList.h SortedLinkedList.cpp
	$(CC) $(CFLAGS) -o SortedLinkedList SortedLinkedList.h SortedLinkedList.cpp

clean:
	rm -rf main
	rm -rf ItemType
	rm -rf SortedLinkedList
	rm -rf *.o
