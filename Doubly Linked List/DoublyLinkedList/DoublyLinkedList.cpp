#include <iostream>
#include <bits/stdc++.h>
#include "DoublyLinkedList.h"

using namespace std;

/**
 * Creates a new DoublyLinkedList object.
 */
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() {
    head = NULL;
    length = 0;
} //DoublyLinkedList

/**
 * Destructs this DoublyLinkedList object.
 */
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    NodeType<T> *temp = head;
    NodeType<T> *tempNext = NULL;
    for (int i = 0; i < length; i++) {
        tempNext = temp->next;
        delete temp;
        temp = tempNext;
    }
    tempNext = NULL;
} //~DoublyLinkedList

/**
 * Inserts a new item of type T into the list.
 *
 * @param item the item to be inserted into the list.
 */
template <typename T>
void DoublyLinkedList<T>::insertItem(T &item) {
    NodeType<T> *node = new NodeType<T>;
    node->data = item;
    node->next = NULL;
    node->back = NULL;
    if (head == NULL) { //Empty list
        head = node;
        length++;
    } else if (item < head->data) { //First element in the list
        node->next = head;
        head->back = node;
        head = node;
        length++;
    } else { //Middle or last element of the list
        NodeType<T> *it = head;
        while ((it->next != NULL) && (it->data < item)) {
            it = it->next;
        } //while
        if (it->data > item || it->next != NULL) { //If it's the last element we don't need to change the back of the Node in front (since it's NULL)
            node->back = it->back;
            node->next = it;
            it->back->next = node;
            it->back = node;
        } else {
            node->back = it;
            it->next = node;
        }
        length++;
    } //if else
} //insertItem

/**
 * Removes the item item from the list, if applicable.
 *
 * @param item the item to be removed from the list.
 */
template <typename T>
void DoublyLinkedList<T>::deleteItem(T &item) {
    NodeType<T> *it = head;
    while (it != NULL && it->data != item) {
        it = it->next;
    } //while
    if (it != NULL) {
        if (it->next == NULL && it->back == NULL) { //Only element in the list
            delete it;
            head = NULL;
        } else if (it->back == NULL) { //First element in the list
            head = head->next;
            head->back = NULL;
            delete it;
        } else { //Middle or last element of the list
            it->back->next = it->next;
            if (it->next != NULL) { //If not the last element
                it->next->back = it->back;
            } //if
            delete it;
        } //if else
        length--;
    } else if (head == NULL) {
        cout << "You cannot delete from an empty list." << endl;
    } else {
        cout << "Item not in list!" << endl;
    } //if else
} //deleteItem

/**
 * Returns the variable length, which holds how many items are in the list.
 *
 * @return the length of the list.
 */
template <typename T>
int DoublyLinkedList<T>::lengthIs() const {
    return length;
} //lengthIs

/**
 * Prints out the list starting from the beginning.
 */
template <typename T>
void DoublyLinkedList<T>::print() {
    NodeType<T> *it = head;
    for (int i = 0; i < length; i++) {
        /*The commented code is for debegguing only*/
        cout << "Printing: " << it->data << endl << "\tBack: ";
        if (it->back == NULL) cout << "NULL" << endl;
        else cout << it->back->data << endl;
        cout << "\tNext: ";
        if (it->next == NULL) cout << "NULL" << endl;
        else cout << it->next->data << endl;
        cout << endl;
        it = it->next;
        /* This is the regular print function*/
        cout << it->data << " ";
        it = it->next;
    }
    cout << endl;
} //print

/**
 * Prints out the list starting from the end.
 */
template <typename T>
void DoublyLinkedList<T>::printReverse() {
    NodeType<T> *it = head;
    for (int i = 0; i < length - 1; i++) {
        it = it->next;
    }
    for (int i = 0; i < length; i++) {
        cout << it->data << " ";
        it = it->back;
    }
    cout << endl;
} //printReverse

/**
 * Removes elements from the list that fall between lower and upper (inclusive).
 *
 * @param lower the lower bounds.
 * @param upper the upper bounds.
 */
template <typename T>
void DoublyLinkedList<T>::deleteSubsection(T lower, T upper) {
    NodeType<T> *it = head;
    while (it != NULL && it->data < lower) {
        it = it->next;
    } //while
    if (it != NULL) {
        while (it != NULL && it->data <= upper) {
            if (it->next != NULL) {
                it = it->next;
                deleteItem(it->back->data);
            } else {
                deleteItem(it->data);
            }
        } //while
    } //if
} //deleteSubsection

/**
 * Returns the mode of the list.
 *
 * @returns the most of the list.
 */
template <typename T>
T DoublyLinkedList<T>::mode() {
    NodeType<T> *it = head;
    int counter = 0, modeCounter = 0;;
    T checkVal = it->data, mode = it->data;

    for (int i = 0; i < length; i++) {
        if (it->data == checkVal) {
            counter++;
        } //if
        if (it->next == NULL || it->data != checkVal) {
            if (counter > modeCounter) {
                modeCounter = counter;
                mode = it->back->data;
            } //if
            checkVal = it->data;
            counter = 1;
        } //if
        it = it->next;
    } //for

    return mode;
} //mode

/**
 * Swaps the alternate nodes in groups of two.
 * For example a list of: 5 10 15 20
 * Would turn into: 10 5 20 15.
 */
template <typename T>
void DoublyLinkedList<T>::swapAlternate() {
    NodeType<T> *it = head;
    while (it != NULL && it->next != NULL) {
        it->next->back = it->back;
        it->back = it->next;
        it->next = it->next->next;
        it->back->next = it;
        if (it->back->back == NULL) {
            head = it->back;
        } else {
            it->back->back->next = it->back;
        }

        if (it->next != NULL) {
            it->next->back = it;
        }
        it = it->next;
    } //while
} //swapAlternate

template class DoublyLinkedList<int>; //This list can support integer values
template class DoublyLinkedList<float>; //This list can support float values
template class DoublyLinkedList<string>; //This list can support string values
