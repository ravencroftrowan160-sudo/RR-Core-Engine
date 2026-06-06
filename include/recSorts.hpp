#ifndef RECSORTS_HPP
#define RECSORTS_HPP

// Heapsort: sorts array[0..length-1] in ascending order
void heapSort(int arr[], int length);

// Mergesort: sorts array[0..length-1] in ascending order
void mergeSort(int arr[], int length);

void quickSort(int arr[], int length);
int findNth(int arr[], int length, int n);

#endif