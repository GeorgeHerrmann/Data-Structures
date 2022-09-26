#include <iostream>
#include <fstream>
#include "BinaryTree.h"

using namespace std;
/**
 * A driver program to test BinaryTree.cpp.
 */
int main(int agrc, char * argv[]) {
    char listType;
    cout << "Enter list type (i - int, f - float, s - std::string): ";
    cin >> listType; //The examples do not require a check if they don't input i, f or s, therefore we can assume it will be one of them

    fstream file;
    file.open(argv[1]);

    if (listType == 'i') { //Drives the list for integer values
        BinaryTree<int> tree1;
        int data;
        bool running = true;
        while (file >> data) {
            tree1.insert(tree1.getRoot(), data);
        }

        cout << "Commands:\ninsert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes (f), getSumOfSubtrees(t), quit (q)" << endl;

        while (running) {
            char command;
            cout << "Enter a command: ";
            cin >> command;

            if (command == 'i') {
                int num;
                cout << "Item to insert: ";
                cin >> num;
                tree1.insert(tree1.getRoot(), num);
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'd') {
                int num;
                cout << "Item to delete: ";
                cin >> num;
                tree1.deleteItem(tree1.getRoot(), num);
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'r') {
                int num;
                cout << "Item to be retrieved: ";
                cin >> num;
                bool r;
                tree1.retrieve(tree1.getRoot(), num, r);
                if (r) cout << "Item found in tree." << endl;
                if (!r) cout << "Item not in tree." << endl;
            } else if (command == 'l') {
                cout << "Tree Length: " << tree1.getLength(tree1.getRoot()) << endl;
            } else if (command == 'n') {
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'p') {
                cout << "Pre-Order: ";
                tree1.preOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'o') {
                cout << "Post-Order: ";
                tree1.postOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 's') {
                cout << "Number of Single Parents: " << tree1.getNumSingleParent(tree1.getRoot()) << endl;
            } else if (command == 'f') {
                cout << "Number of leaf nodes: " << tree1.getNumLeafNodes(tree1.getRoot()) << endl;
            } else if (command == 't') {
                int num;
                cout << "Item to get sum of subtrees: ";
                cin >> num;
                bool found = false;
                int sum = tree1.getSumOfSubtrees(tree1.getRoot(), num, found);
                if (found) {
                    cout << "Sum of Subtrees: " << sum << endl;
                } else {
                    cout << "Item not in tree." << endl;
                }
            } else if (command == 'q') {
                cout << "Quitting program..." << endl;
                running = false;
            } else {
                cout << "Command not recognized. Try again" << endl;
            }
            cout << endl;
        }
    } else if (listType == 'f') { //Drives the list for float values
        BinaryTree<float> tree1;
        float data;
        bool running = true;
        while (file >> data) {
            tree1.insert(tree1.getRoot(), data);
        }

        cout << "Commands:\ninsert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes (f), getSumOfSubtrees(t), quit (q)" << endl;

        while (running) {
            char command;
            cout << "Enter a command: ";
            cin >> command;

            if (command == 'i') {
                float num;
                cout << "Item to insert: ";
                cin >> num;
                tree1.insert(tree1.getRoot(), num);
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'd') {
                float num;
                cout << "Item to delete: ";
                cin >> num;
                tree1.deleteItem(tree1.getRoot(), num);
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'r') {
                float num;
                cout << "Item to be retrieved: ";
                cin >> num;
                bool r;
                tree1.retrieve(tree1.getRoot(), num, r);
                if (r) cout << "Item found in tree." << endl;
                if (!r) cout << "Item not in tree." << endl;
            } else if (command == 'l') {
                cout << "Tree Length: " << tree1.getLength(tree1.getRoot()) << endl;
            } else if (command == 'n') {
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'p') {
                cout << "Pre-Order: ";
                tree1.preOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'o') {
                cout << "Post-Order: ";
                tree1.postOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 's') {
                cout << "Number of Single Parents: " << tree1.getNumSingleParent(tree1.getRoot()) << endl;
            } else if (command == 'f') {
                cout << "Number of leaf nodes: " << tree1.getNumLeafNodes(tree1.getRoot()) << endl;
            } else if (command == 't') {
                float num;
                cout << "Item to get sum of subtrees: ";
                cin >> num;
                bool found = false;
                float sum = tree1.getSumOfSubtrees(tree1.getRoot(), num, found);
                if (found) {
                    cout << "Sum of Subtrees: " << sum << endl;
                } else {
                    cout << "Item not in tree." << endl;
                }
            } else if (command == 'q') {
                cout << "Quitting program..." << endl;
                running = false;
            } else {
                cout << "Command not recognized. Try again" << endl;
            }
            cout << endl;
        }
    } else if (listType == 's') { //Drives the list for std::string values
        BinaryTree<string> tree1;
        string data;
        bool running = true;
        while (file >> data) {
            tree1.insert(tree1.getRoot(), data);
        }

        cout << "Commands:\ninsert (i), delete (d), retrieve (r), length (l), in-order (n), pre-order (p), post-order (o), getNumSingleParent (s), getNumLeafNodes (f), getSumOfSubtrees(t), quit (q)" << endl;

        while (running) {
            char command;
            cout << "Enter a command: ";
            cin >> command;

            if (command == 'i') {
                string num; //Okay technically this isn't a number anymore but I'm too lazy to change it
                cout << "Item to insert: ";
                cin >> num;
                tree1.insert(tree1.getRoot(), num);
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'd') {
                string num;
                cout << "Item to delete: ";
                cin >> num;
                tree1.deleteItem(tree1.getRoot(), num);
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'r') {
                string num;
                cout << "Item to be retrieved: ";
                cin >> num;
                bool r;
                tree1.retrieve(tree1.getRoot(), num, r);
                if (r) cout << "Item found in tree." << endl;
                if (!r) cout << "Item not in tree." << endl;
            } else if (command == 'l') {
                cout << "Tree Length: " << tree1.getLength(tree1.getRoot()) << endl;
            } else if (command == 'n') {
                cout << "In-Order: ";
                tree1.inOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'p') {
                cout << "Pre-Order: ";
                tree1.preOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 'o') {
                cout << "Post-Order: ";
                tree1.postOrder(tree1.getRoot());
                cout << endl;
            } else if (command == 's') {
                cout << "Number of Single Parents: " << tree1.getNumSingleParent(tree1.getRoot()) << endl;
            } else if (command == 'f') {
                cout << "Number of leaf nodes: " << tree1.getNumLeafNodes(tree1.getRoot()) << endl;
            } else if (command == 't') {
                string num;
                cout << "Item to get sum of subtrees: ";
                cin >> num;
                bool found = false;
                string sum = tree1.getSumOfSubtrees(tree1.getRoot(), num, found);
                if (found) {
                    cout << "Sum of Subtrees: " << sum << endl;
                } else {
                    cout << "Item not in tree." << endl;
                }
            } else if (command == 'q') {
                cout << "Quitting program..." << endl;
                running = false;
            } else {
                cout << "Command not recognized. Try again" << endl;
            }
            cout << endl;
        }
    }

    return 0;


}
