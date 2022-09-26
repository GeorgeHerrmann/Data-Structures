#include "SortedLinkedList.h"

/**
 * Constructs a new SortedLinkedList.
 */
SortedLinkedList::SortedLinkedList() {
    listLength = 0;
    head = new ListNode;
    currentPos = new ListNode;
    iterator = new ListNode;
} //SortedLinkedList

/**
 * Destructs this SortedLinkedList
 */
SortedLinkedList::~SortedLinkedList() {
    delete head;
    delete currentPos;
    delete iterator;
} //~SortedLinkedList

/**
 * Returns the length of the SortedLinkedList
 *
 * @returns the length of the list
 */
int SortedLinkedList::length() const {
    return listLength;
} //length

/**
 * Inserts a new item into the linked list.
 *
 * @param item the item to be inserted
 */
void SortedLinkedList::insertItem(ItemType item) {
    iterator = head;
    //cout << length() << endl;
    if (length() == 0) {
        //cout << "INSIDE ONE" << endl;
        head->item.initialize(item.getValue());
        listLength++;
    } else if (head->item.compareTo(item) == GREATER) {
        //cout << "INSIDE TWO" << endl;
        ListNode *tempNode = new ListNode;
        tempNode->item = item;
        tempNode->next = iterator;
        head = tempNode;
        listLength++;
    } else {
        //cout << "INSIDE THREE" << endl;
        if (searchItem(item) != -1) {
            cout << "Sorry. You cannot insert the duplicate item." << endl;
        } else {
            for (int i = 0; i < length(); i++) {
                if (iterator->next == NULL) {
                    ListNode *tempNode = new ListNode;
                    tempNode->item = item;
                    iterator->next = tempNode;
                    listLength++;
                    i = length();
                } else if (iterator->next->item.compareTo(item) == GREATER) {
                    ListNode *tempNode = new ListNode;
                    tempNode->item = item;
                    tempNode->next = iterator->next;
                    iterator->next = tempNode;
                    listLength++;
                    i = length();
                } else {
                    iterator = iterator->next;
                }
            }
        }
    }
} //insertItem

/**
 * Removed an item from this linked list.
 *
 * @param item the item to be removed
 */
void SortedLinkedList::deleteItem(ItemType item) {
    bool found = false;
    iterator = head;
    if (length() == 0) {
        cout << "You cannot delete from an empty list." << endl;
    } else if (length() == 1) {
        if (iterator->item.compareTo(item) == EQUAL) {
            head = NULL;
            currentPos = NULL;
            iterator = NULL;
            found = true;
            listLength--;
        }
    } else {
        if (iterator->item.compareTo(item) == EQUAL) {
            head = head->next;
            found = true;
            listLength--;
        } else {
            for (int i = 0; i < length() - 1; i++) {
                if (iterator->next->item.compareTo(item) == EQUAL) {
                    ListNode *temp = iterator->next;
                    iterator->next = temp->next;
                    found = true;
                    i = length();
                    listLength--;
                }
                if (iterator->next != NULL) {
                    iterator = iterator->next;
                }
            }
        }
    }
    if (!found && length() != 0) {
        cout << "Item not found." << endl;
    }
} //deleteItem

/**
 * Returns the index of the item in this linked list.
 *
 * @param item the item to be searched for.
 * @returns the index of item in this list
 */
int SortedLinkedList::searchItem(ItemType item) {
    ListNode *searchIterator = head;
    //cout << "Searching " << item.getValue() << endl;
    for (int i = 0; i < length(); i++) {
        if (searchIterator->item.compareTo(item) == EQUAL) {
            return i;
        }
        searchIterator = searchIterator->next;
    }
    //cout << "Item not found." << endl;
    return -1;
} //searchItem

/**
 * Returns the next item in the list.
 * 
 * @returns the next itme in the list.
 */
ItemType SortedLinkedList::getNextItem() {
    ItemType returnItem;
    if (length() == 0) {
        throw invalid_argument("List is empty");
    } else if (currentPos == NULL) {
        currentPos = head;
    }
    if (currentPos->item.getValue() == 0) {
        currentPos = head;
    }
    returnItem = currentPos->item;
    currentPos = currentPos->next;
    return returnItem;
} //getNextItem

/**
 * Resets the currentPos pointer to head.
 */
void SortedLinkedList::resetList() {
    currentPos = head;
} //resetList

/**
 * Merges two lists together.
 *
 * @param list the list to be merged with this list.
 */
void SortedLinkedList::mergeFunction(SortedLinkedList list) {
    /* Check for duplicates first */
    bool pass = true;
    ListNode *iterator2 = head;
    for (int i = 0; i < list.length(); i++) {
        int x = list.searchItem(iterator2->item);
        if (x != -1) {
            cout << "Sorry. You cannot insert the duplicate item." << endl;
            pass = false;
        }
        if (iterator2->next != NULL) {
            iterator2 = iterator2->next;
        }
    }
    iterator2 = list.getHead();
    if (pass) {
        for (int i = 0; i < list.length(); i++) {
            insertItem(iterator2->item);
            iterator2 = iterator2->next;
        }
    }
} //mergeFunction

/**
 * Removed every other item from this list.
 */
void SortedLinkedList::deleteAlternateNodes() {
    ListNode *temperator = head;
    int l = listLength;
    for (int i = 0; i <= l; i++) {
        if (i % 2 != 0 && temperator->next != NULL) {
            deleteItem(temperator->item);
        }
        if (temperator->next != NULL) {
            temperator = temperator->next;
        }
    }
} //deleteAlternateNodes

/**
 * Finds all common elements between the input list and this list and makes this list those elements.
 *
 * @param list the list to compare to.
 */
void SortedLinkedList::findCommonElements(SortedLinkedList list) {
    ListNode *temperator = head;
    for (int i = 0; i <= length(); i++) {
        if (list.searchItem(temperator->item) == -1) {
            //cout << "Delete " << temperator->item.getValue() << endl;
            deleteItem(temperator->item);
            temperator = head;
            i = 0;
        } else {
            temperator = temperator->next;
        }
    }
} //findCommonElements

/**
 * Returns the item pointed to by the iterator pointer
 *
 * @returns the item pointed to by the iterator pointer
 */
ItemType SortedLinkedList::getItem() {
    return iterator->item;
} //getNext

/**
 * Returns the head pointer.
 *
 * @returns the head pointer.
 */
ListNode* SortedLinkedList::getHead() {
    return head;
} //getHead

/**
 * Prints all integers in this list in order.
 */
void SortedLinkedList::printElements() {
    iterator = head;
    for (int i = 0; i < length(); i++) {
        cout << iterator->item.getValue() << " ";
        iterator = iterator->next;
    }
    cout << endl;
} //printElements
