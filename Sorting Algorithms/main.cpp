#include "Sorting.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

void main2(); //Main 2 is for experiment 2

/**
 * A driver function for experiment 1 of assignment 5.
 * @param argc how many command-line arguments.
 * @param argv the command-line arguments.
 * @returns the exit status.
 */
int main(int argc, char * argv[]) {
    if (argc == 1) { //If no input file is given we assume they want experiment 2, so we call main2()
        main2();
        return 0; //And we stop this function
    }
    fstream file;
    file.open(argv[1]);
    int data; //Temporary variable for reading from a file
    int arr[100000]; //Arr holds the data
    int n = 0; //N holds how many data members are in the array
    for (int i = 0; file >> data; i++) { //Reads the data
        arr[i] = data;
        n++;
    }
    /* Prompts the user for input */
    cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp (q) quick-sort-rp (r)" << endl;
    cout << "Enter the algorithm: ";
    char alg; //alg holds which sorting algorithm they want
    cin >> alg;
    long counter = 0; //Counter holds how many comparisons each algorithm makes

    /* Calls the correct sorting algorithm based on input */
    if (alg == 's') {
        selectionSort(counter, arr, n, 0);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Selection-sort comparisons: " << counter << endl;
    } else if (alg == 'm') {
        mergeSort(counter, arr, 0, n - 1);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Merge-sort comparisons: " << counter << endl;
    } else if (alg == 'h') {
        heapSort(counter, arr, n);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Heap-sort comparisons: " << counter << endl;
    } else if (alg == 'q') {
        quickSort(counter, arr, 0, n - 1, 0);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Quick-sort-fp comparisons: " << counter << endl;
    } else if (alg == 'r') {
        quickSort(counter, arr, 0, n - 1, 1);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Quick-sort-rp comparisons: " << counter << endl;
    } else {
        cout << "Invalid input... exiting" << endl;
    }
    return 0;
} //main

/**
 * A driver function for experiment 2 of assignment 5.
 */
void main2() {
    int n; //Basically everything else is the same but we do not read from a file here
    cout << "Enter how many digits you'd like to sort: ";
    cin >> n; //Instead we prompt the user for the number of digits and assign them ourselves
    int arr[100000];
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 100; //Gets randomized data 0-99
    } //for

    cout << "selection-sort (s) merge-sort (m) heap-sort (h) quick-sort-fp (q) quick-sort-rp (r)" << endl;
    cout << "Enter the algorithm: ";
    char alg;
    cin >> alg;
    long counter = 0;

    if (alg == 's') {
        selectionSort(counter, arr, n, 0);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Selection-sort comparisons: " << counter << endl;
    } else if (alg == 'm') {
        mergeSort(counter, arr, 0, n - 1);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Merge-sort comparisons: " << counter << endl;
    } else if (alg == 'h') {
        heapSort(counter, arr, n);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Heap-sort comparisons: " << counter << endl;
    } else if (alg == 'q') {
        quickSort(counter, arr, 0, n - 1, 0);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Quick-sort-fp comparisons: " << counter << endl;
    } else if (alg == 'r') {
        quickSort(counter, arr, 0, n - 1, 1);
        cout << "1 2 3 4 5 ……………. " << n-1 << endl;
        cout << "\t#Quick-sort-rp comparisons: " << counter << endl;
    } else {
        cout << "Invalid input... exiting" << endl;
    }

} //main
