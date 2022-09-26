#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

using namespace std;

/**
 * A NodeType is a Node housed in a DoublyLinkedList that holds some data as well as
 * the nodes before and after it.
 */
template<class T>
struct NodeType {
    T data;
    NodeType<T> *next = NULL; //By default we assume there is nothing next or behind the Node unless specified
    NodeType<T> *back = NULL;
};

/**
 * A DoublyLinkedList is a linked list where each node holds the nodes before and after it.
 */
template<class T> //Can support integers, floats and strings
class DoublyLinkedList {
    private:
        int length;
        NodeType<T> *head;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void insertItem(T &item);
        void deleteItem(T &item);
        int lengthIs() const;
        void print();
        void printReverse();
        void deleteSubsection(T upper, T lower);
        T mode();
        void swapAlternate();
};

#endif
