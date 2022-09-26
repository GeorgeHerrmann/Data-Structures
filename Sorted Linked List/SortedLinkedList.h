#ifndef SORTEDLINKEDLIST_H
#define SORTEDLINKEDLIST_H

#include "ItemType.h"
#include "ListNode.h"
#include <iostream>
using namespace std;

class SortedLinkedList {
    private:
        int listLength;
        ListNode *head;
        ListNode *currentPos;
        ListNode *iterator;
    public:
        SortedLinkedList();
        ~SortedLinkedList();
        int length() const;
        void insertItem(ItemType item);
        void deleteItem(ItemType item);
        int searchItem(ItemType item);
        ItemType getNextItem();
        void resetList();
        void mergeFunction(SortedLinkedList list);
        void deleteAlternateNodes();
        void findCommonElements(SortedLinkedList list);
        ItemType getItem();
        ListNode* getHead();
        void printElements();
};

#endif
