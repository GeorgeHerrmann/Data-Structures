#include "Sorting.h"
#include <iostream>
#include <stdlib.h>

/**
 * Finds the index of the smallest value in the provided array.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data itself in array format
 * @param start the index where we start searching (unsorted)
 * @param end the index where we stop searching
 * @return the index of the smallest value
 */
int minIndex(long &count, int values[], int start, int end) {
    int indexOfMin = start;

    for (int index = start + 1; index <= end; index++) {
        count++;
        if (values[index] < values[indexOfMin]) {
            indexOfMin = index;
        } //if
    } //for

    return indexOfMin;
} //minIndex

/**
 * Sorts the array using the Selection Sort algorithm.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data in an array
 * @param numValues how many values need to be sorted
 * @param index the index to begin sorting
 */
void selectionSort (long &count, int values[], int numValues, int index) {
    if (index == numValues) {
        return;
    } //if

    int k = minIndex(count, values, index, numValues - 1);

    if (k != index) {
        swap (values[k], values[index]);
    } //if
    count++;

    selectionSort(count, values, numValues, index + 1);
} //selectionSort

/**
 * Sorts the data using the Merge Sort algorithm.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data in an array
 * @param first the index of the first item to begin sorting
 * @param last the index of the last item to begin sorting
 */
void mergeSort (long &count, int values[], int first, int last) {
    count++;
    if (first < last) {
        int middle = (first + last) / 2;
        mergeSort(count, values, first, middle);
        mergeSort(count, values, middle + 1, last);

        merge(count, values, first, middle, middle + 1, last);
    } //if
} //mergeSort

/**
 * Merges the data from the Merge Sort algorithm.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data in an array
 * @param leftFirst the index of the left most value
 * @param leftLast the index of the second left most value
 * @param rightFirst the index of the second right most value
 * @param rightLast the index of the right most value
 */
void merge (long &count, int values[], int leftFirst, int leftLast, int rightFirst, int rightLast) {
    int tempArray[100000];
    int index = leftFirst;
    int saveFirst = leftFirst;

    while ((leftFirst <= leftLast) && (rightFirst <= rightLast)) {
        count ++;
        if (values[leftFirst] < values[rightFirst]) {
            tempArray[index] = values[leftFirst];
            leftFirst++;
        } else {
            tempArray[index] = values[rightFirst];
            rightFirst++;
        } //if
        index++;
    } //while

    while (leftFirst <= leftLast) {
        count++;
        tempArray[index] = values[leftFirst];
        leftFirst++;
        index++;
    } //while

    while (rightFirst <= rightLast) {
        count++;
        tempArray[index] = values[rightFirst];
        rightFirst++;
        index++;
    } //while

    for (index = saveFirst; index <= rightLast; index++) {
        count++;
        values[index] = tempArray[index];
    } //for
} //merge


/**
 * Sorts the data using the Heap Sort algorithm.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data in an array
 * @param numValues how many values still need to be sorted
 */
void heapSort (long &count, int values[], int numValues) {
    int index;
    for (index = (numValues / 2) - 1; index >= 0; index--) {
        count++;
        reheapDown(count, values, index, numValues - 1);
    } //for

    for (index = numValues - 1; index >= 1; index--) {
        count++;
        swap(values[0], values[index]);
        reheapDown(count, values, 0, index - 1);
    } //for
} //heapSort

/**
 * Maintains the heap structure for Heap Sort.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data in an array
 * @param root the root value (greatest value) in the heap
 * @param bottom the bottom-most value in the heap array
 */
void reheapDown (long &count, int values[], int root, int bottom) {
    int maxChild, rightChild, leftChild;
    leftChild = root * 2 + 1;
    rightChild = root * 2 + 2;

    count++;
    if (leftChild <= bottom) {
        count++;
        if (leftChild == bottom) {
            maxChild = leftChild;
        } else {
            count++;
            if (values[leftChild] <= values[rightChild]) {
                maxChild = rightChild;
            } else {
                maxChild = leftChild;
            }
        }
        count++;
        if (values[root] < values[maxChild]) {
            swap(values[root], values[maxChild]);
            reheapDown(count, values, maxChild, bottom);
        }
    }
} //reheapDown

/**
 * Splits the data for the Quick Sort algorithm.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data in an array
 * @param start the first index where we begin sorting
 * @param end the last index where we begin sorting
 * @returns the index where we now have separated the smallest and largest values
 */
int split (long &count, int values[], int start, int end) {
    int pivot = values[end];
    int i = (start - 1);

    for (int j = start; j < end; j++) {
        count++;
        if (values[j] < pivot) {
            i++;
            swap(values[i], values[j]);
        } //if
    } //for
    swap(values[i + 1], values[end]);
    return (i + 1);
} //split

/**
 * Calls the Split function but passes a random splitpoint instead of a set one.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data in an array
 * @param start the index where we must begin sorting
 * @param end the index where we must stop sorting.
 * @returns the index where the smallest values are on the left and greatest on the right
 */
int splitRandom (long &count, int values[], int start, int end) {
    srand(time(NULL));
    int random = start + rand() % (start - end);

    swap(values[random], values[end]);

    return split(count, values, start, end);
} //splitRandom

/**
 * Sorts the data using the Quick Sort algorithm.
 *
 * @param count counts how many comparisons the function makes
 * @param values the data in an array
 * @param start the index where we must begin sorting
 * @param end the index where we must stop sorting
 * @param type 0 for First Pivot QuickSort, 1 for Random Pivot QuickSort
 */
void quickSort(long &count, int values[], int start, int end, int type) {
    count ++;
    if (start < end) {
        int s;
        if (type == 0) {
            s = split(count, values, start, end);
        } else {
            s = splitRandom(count, values, start, end);
        }

        quickSort(count, values, start, s - 1, type);
        quickSort(count, values, s + 1, end, type);
    } //if
} //quickSort
