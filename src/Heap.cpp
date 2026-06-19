#include "Heap.hpp"
#include <stdexcept>

Heap::Heap(int cap) : arr(new int[cap + 1]), size(0), capacity(cap){
}

Heap::~Heap(){
    delete[] arr;
}

void Heap::resize(){
    // double the capacity
    int newCap = capacity * 2;

    // allocate new array (+1 because index 0 is unused)
    int* newArr = new int[newCap + 1];

    // copy old values (1..size)
    for (int i = 1; i <= size; i++) {
        newArr[i] = arr[i];
    }

    // delete old array
    delete[] arr;

    // update pointer + capacity
    arr = newArr;
    capacity = newCap;
}

void Heap::bubbleUp(int index) {
    // While we are not at the root AND the child is smaller than the parent
    while (index > 1 && arr[index] < arr[index / 2]) {
        // swap with parent
        int temp = arr[index];
        arr[index] = arr[index / 2];
        arr[index / 2] = temp;

        // move upward
        index = index / 2;
    }
}

void Heap::trickleDown(int index) {
    while (true) {
        int left = index * 2;
        int right = index * 2 + 1;

        // If no children, stop
        if (left > size) {
            break;
        }

        // Determine the smaller child
        int smaller = left;
        if (right <= size && arr[right] < arr[left]) {
            smaller = right;
        }

        // If parent is already smaller than both children, stop
        if (arr[index] <= arr[smaller]) {
            break;
        }

        // Otherwise swap with smaller child
        int temp = arr[index];
        arr[index] = arr[smaller];
        arr[smaller] = temp;

        // Move down to the child we swapped with
        index = smaller;
    }
}

void Heap::addItem(int val) {
    // If the heap is full, resize first
    if (size == capacity) {
        resize();
    }

    // Insert new value at the next open position
    size++;
    arr[size] = val;

    // Restore heap property by bubbling upward
    bubbleUp(size);
}

int Heap::getItem() {
    if (size == 0) {
        throw std::runtime_error("Removal from empty heap");
    }

    int minVal = arr[1];
    arr[1] = arr[size];
    size--;

    if (size > 0) {
        trickleDown(1);
    }

    return minVal;
}