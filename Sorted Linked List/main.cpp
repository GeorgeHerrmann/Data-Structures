#include "SortedLinkedList.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

/**
 * A driver program for SortedLinkedList.cpp
 */
int main(int argc, char* argv[]) {
    SortedLinkedList list1;
    fstream file;
    int data;

    file.open(argv[1]);

    ItemType item;
    while (file >> data) {
        item.initialize(data);
        list1.insertItem(item);
        //list1.printElements();
    }


    bool running = true;
    cout << "Commands: \n"
            << "(i) - Insert value\n"
            << "(d) - Delete value\n"
            << "(s) - Search value\n"
            << "(n) - Print next iterator value\n"
            << "(r) - Reset iterator\n"
            << "(a) - Delete alternate nodes\n"
            << "(m) - Merge two lists\n"
            << "(t) - Intersection\n"
            << "(p) - Print list\n"
            << "(l) - Print length\n"
            << "(q) - Quit program" << endl;
    while (running) {
        cout << "Enter a command: ";
        char input;
        int numInput = 0;
        ItemType itemInput;
        cin >> input;

        if (input == 'i') {
            list1.printElements();
            cout << "Enter number: ";
            cin >> numInput;
            itemInput.initialize(numInput);
            list1.insertItem(itemInput);
            list1.printElements();
        } else if (input == 'd') {
            list1.printElements();
            cout << "Enter value to delete: ";
            cin >> numInput;
            itemInput.initialize(numInput);
            list1.deleteItem(itemInput);
            list1.printElements();
        } else if (input == 's') {
            cout << "Enter a value to search: ";
            cin >> numInput;
            ItemType item;
            item.initialize(numInput);
            if (list1.searchItem(item) != -1) {
                cout << "Index " << list1.searchItem(item) << endl;
            } else {
                cout << "Item not found." << endl;
            }
        } else if (input == 'n') {
            try {
                cout << list1.getNextItem().getValue() << endl;
            } catch (invalid_argument& e) {
                cout << e.what() << endl;
            }
        } else if (input == 'r') {
            list1.resetList();
            cout << "Iterator reset." << endl;
        } else if (input == 'a') {
            cout << "List before alternate delete: ";
            list1.printElements();
            cout << "List after alternate delete: ";
            list1.deleteAlternateNodes();
            list1.printElements();
        } else if (input == 'm') {
            string elements, singleElement;
            cout << "Length of list to merge: ";
            cin >> numInput;
            cin.ignore(256, '\n');
            cout << "List elements separated by spaces in order: ";
            getline(cin, elements);
            stringstream stream(elements);
            SortedLinkedList list2;
            while (getline(stream, singleElement, ' ')) {
                ItemType l2;
                l2.initialize(stoi(singleElement));
                list2.insertItem(l2);
            }
            cout << "List 1: ";
            list1.printElements();
            cout << "List 2: ";
            list2.printElements();
            list1.mergeFunction(list2);
            list1.printElements();
        } else if (input == 't') {
            string elements, singleElement;
            cout << "Length of list to find intersection: ";
            cin >> numInput;
            cin.ignore(256, '\n');
            cout << "List elements separated by spaces in order: ";
            getline(cin, elements);
            stringstream stream(elements);
            SortedLinkedList list2;
            while (getline(stream, singleElement, ' ')) {
                ItemType l2;
                l2.initialize(stoi(singleElement));
                list2.insertItem(l2);
            }
            cout << "List 1: ";
            list1.printElements();
            cout << "List 2: ";
            list2.printElements();
            list1.findCommonElements(list2);
            cout << "Intersection: ";
            list1.printElements();
        } else if (input == 'p') {
            list1.printElements();
        } else if (input == 'l') {
            cout << "List Length is " << list1.length() << endl;
        } else if (input == 'q') {
            cout << "Quitting program..." << endl;
            running = false;
        } else {
            cout << "Invalid command, try again!" << endl;
        }
    }
    return 0;
}
