#include <iostream>
#include <fstream>
#include "DoublyLinkedList.h"

using namespace std;
/**
 * A driver program to test DoublyLinkedList.cpp.
 */
int main(int agrc, char * argv[]) {
    char listType;
    cout << "Enter list type (i - int, f - float, s - std::string): ";
    cin >> listType; //The examples do not require a check if they don't input i, f or s, therefore we can assume it will be one of them

    fstream file;
    file.open(argv[1]);

    if (listType == 'i') { //Drives the list for integer values
        DoublyLinkedList<int> list1;
        int data;
        bool running = true;
        while (file >> data) {
            list1.insertItem(data);
        }

        cout << "insert (i), delete (d), length(l), print(p), deleteSub(b), mode(m), printReverse(r), swapAlt(s), quit(q)" << endl;

        while (running) {
            char command;
            cout << "Enter a command: ";
            cin >> command;

            if (command == 'p') { //print
                list1.print();
            } else if (command == 'r') { //print reverse
                list1.printReverse();
            } else if (command == 'l') { //lengthIs
                cout << "The length is: " << list1.lengthIs() << endl;
            } else if (command == 'i') { //insert
                int inserter;
                cout << "Item to insert: ";
                cin >> inserter;
                list1.insertItem(inserter);
                list1.print();
            } else if (command == 'd') { //delete
                int deleter;
                cout << "Item to delete: ";
                cin >> deleter;
                list1.deleteItem(deleter);
                list1.print();
            } else if (command == 'b') { //deleteSubsection
                int upper, lower;
                cout << "Enter lower bound: ";
                cin >> lower;
                cout << "Enter upper bound: ";
                cin >> upper;
                cout << "Original List: ";
                list1.print();
                list1.deleteSubsection(lower, upper);
                cout << "Modified List: ";
                list1.print();
            } else if (command == 's') { //swapAlternate
                cout << "Original List: ";
                list1.print();
                list1.swapAlternate();
                cout << "Swapped List: ";
                list1.print();
            } else if (command == 'm') { //mode
                list1.print();
                cout << "Mode: " << list1.mode() << endl;
            } else if (command == 'q') { //quit
                cout << "Quitting program..." << endl;
                running = false;
            } else { //invalid command
                cout << "Invalid command, try again." << endl;
            }
            cout << endl;
        }
    } else if (listType == 'f') { //Drives the list for float values
        DoublyLinkedList<float> list1;
        float data;
        bool running = true;
        while (file >> data) {
            list1.insertItem(data);
        }

        cout << "insert (i), delete (d), length(l), print(p), deleteSub(b), mode(m), printReverse(r), swapAlt(s), quit(q)" << endl;

        while (running) {
            char command;
            cout << "Enter a command: ";
            cin >> command;

            if (command == 'p') {
                list1.print();
            } else if (command == 'r') {
                list1.printReverse();
            } else if (command == 'l') {
                cout << "The length is: " << list1.lengthIs() << endl;
            } else if (command == 'i') {
                float inserter;
                cout << "Item to insert: ";
                cin >> inserter;
                list1.insertItem(inserter);
                list1.print();
            } else if (command == 'd') {
                float deleter;
                cout << "Item to delete: ";
                cin >> deleter;
                list1.deleteItem(deleter);
                list1.print();
            } else if (command == 'b') {
                float upper, lower;
                cout << "Enter lower bound: ";
                cin >> lower;
                cout << "Enter upper bound: ";
                cin >> upper;
                cout << "Original List: ";
                list1.print();
                list1.deleteSubsection(lower, upper);
                cout << "Modified List: ";
                list1.print();
            } else if (command == 's') {
                cout << "Original List: ";
                list1.print();
                list1.swapAlternate();
                cout << "Swapped List: ";
                list1.print();
            } else if (command == 'm') {
                list1.print();
                cout << "Mode: " << list1.mode() << endl;
            } else if (command == 'q') {
                cout << "Quitting program..." << endl;
                running = false;
            } else {
                cout << "Invalid command, try again." << endl;
            }
            cout << endl;
        }
    } else if (listType == 's') { //Drives the list for std::string values
        DoublyLinkedList<string> list1;
        string data;
        bool running = true;
        while (file >> data) {
            list1.insertItem(data);
        }

        cout << "insert (i), delete (d), length(l), print(p), deleteSub(b), mode(m), printReverse(r), swapAlt(s), quit(q)" << endl;

        while (running) {
            char command;
            cout << "Enter a command: ";
            cin >> command;

            if (command == 'p') {
                list1.print();
            } else if (command == 'r') {
                list1.printReverse();
            } else if (command == 'l') {
                cout << "The length is: " << list1.lengthIs() << endl;
            } else if (command == 'i') {
                string inserter;
                cout << "Item to insert: ";
                cin >> inserter;
                list1.insertItem(inserter);
                list1.print();
            } else if (command == 'd') {
                string deleter;
                cout << "Item to delete: ";
                cin >> deleter;
                list1.deleteItem(deleter);
                list1.print();
            } else if (command == 'b') {
                string upper, lower;
                cout << "Enter lower bound: ";
                cin >> lower;
                cout << "Enter upper bound: ";
                cin >> upper;
                cout << "Original List: ";
                list1.print();
                list1.deleteSubsection(lower, upper);
                cout << "Modified List: ";
                list1.print();
            } else if (command == 's') {
                cout << "Original List: ";
                list1.print();
                list1.swapAlternate();
                cout << "Swapped List: ";
                list1.print();
            } else if (command == 'm') {
                list1.print();
                cout << "Mode: " << list1.mode() << endl;
            } else if (command == 'q') {
                cout << "Quitting program..." << endl;
                running = false;
            } else {
                cout << "Invalid command, try again." << endl;
            }
            cout << endl;
        }
    }

    return 0;


}
