#include "recSorts.hpp"
#include <algorithm>

void heapify(int arr[], int length, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < length && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < length && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(arr[index], arr[largest]);
        heapify(arr, length, largest);
    }
}

void heapSort(int arr[], int length) {
    // Build max heap
    for (int i = length / 2 - 1; i >= 0; i--) {
        heapify(arr, length, i);
    }

    // Extract elements from heap
    for (int i = length - 1; i > 0; i--) {
        std::swap(arr[0], arr[i]);   // move largest to end
        heapify(arr, i, 0);          // restore heap property
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSortRec(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;

    mergeSortRec(arr, left, mid);
    mergeSortRec(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

void mergeSort(int arr[], int length) {
    mergeSortRec(arr, 0, length - 1);
}

int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int i = left + 1;

    for (int j = left + 1; j <= right; j++) {
        if (arr[j] < pivot) {
            std::swap(arr[i], arr[j]);
            i++;
        }
    }

    // place pivot in its final position
    std::swap(arr[left], arr[i - 1]);
    return i - 1;  // pivot index
}

void quickSortRec(int arr[], int left, int right) {
    if (left >= right) return;

    int pivotIndex = partition(arr, left, right);

    quickSortRec(arr, left, pivotIndex - 1);
    quickSortRec(arr, pivotIndex + 1, right);
}

void quickSort(int arr[], int length) {
    quickSortRec(arr, 0, length - 1);
}

int findNthRec(int arr[], int left, int right, int n) {
    int pivotIndex = partition(arr, left, right);

    if (pivotIndex == n) {
        return arr[pivotIndex];
    } else if (n < pivotIndex) {
        return findNthRec(arr, left, pivotIndex - 1, n);
    } else {
        return findNthRec(arr, pivotIndex + 1, right, n);
    }
}

int findNth(int arr[], int length, int n) {
    return findNthRec(arr, 0, length - 1, n);
}