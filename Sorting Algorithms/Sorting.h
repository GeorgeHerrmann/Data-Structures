#ifndef SORTING_H
#define SORTING_H

using namespace std;

/**
 * This is the class definition for the four sorting algorithms.
 */
    int minIndex(long &count, int values[], int start, int end); //Helper function for selection sort
    void selectionSort (long &count, int values[], int numValues, int index);
    void mergeSort (long &count, int values[], int first, int last);
    void merge (long &count, int values[], int leftFirst, int leftLast, int rightFirst, int rightLast); //Helper function for merge sort
    void heapSort (long &count, int values[], int numValues);
    void reheapDown (long &count, int values[], int root, int bottom); //Helper function for heap sort
    int split (long &count, int values[], int start, int end); //Helper function for quick sort
    int splitRandom (long &count, int values[], int start, int end);
    void quickSort (long &count, int values[], int start, int end, int type);

#endif
