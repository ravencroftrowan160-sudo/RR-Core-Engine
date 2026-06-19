#include "Deque.hpp"
#include <stdexcept>
#include <sstream>

// Default constructor
template <typename T>
Deque<T>::Deque()
    : capacity(10), data(new T[capacity]), left(0), right(0), count(0) {}

// Constructor with initial capacity
template <typename T>
Deque<T>::Deque(int initialCapacity)
    : capacity(initialCapacity), data(new T[initialCapacity]),
      left(0), right(0), count(0) {}

// Destructor
template <typename T>
Deque<T>::~Deque() {
    delete[] data;
}

// Add to tail
template <typename T>
void Deque<T>::addTail(const T& value) {
    if (count == capacity) {
        resize();
    }

    data[right] = value;
    right = (right + 1) % capacity;
    count++;
}

// Add to head
template <typename T>
void Deque<T>::addHead(const T& value) {
    if (count == capacity) {
        resize();
    }

    left = ((left - 1) + capacity) % capacity;
    data[left] = value;
    count++;
}

// Remove from head
template <typename T>
T Deque<T>::removeHead() {
    if (isEmpty()) {
        throw std::out_of_range("Array is empty in removeHead");
    }

    T savedValue = data[left];
    left = (left + 1) % capacity;
    count--;

    return savedValue;
}

// Remove from tail
template <typename T>
T Deque<T>::removeTail() {
    if (isEmpty()) {
        throw std::out_of_range("Array is empty in removeTail");
    }

    right = ((right - 1) + capacity) % capacity;
    T savedValue = data[right];
    count--;

    return savedValue;
}

// Resize internal array
template <typename T>
void Deque<T>::resize() {
    int newCapacity = capacity * 2;
    T* newArray = new T[newCapacity];

    for (int i = 0; i < count; i++) {
        newArray[i] = data[(left + i) % capacity];
    }

    delete[] data;
    data = newArray;
    capacity = newCapacity;

    left = 0;
    right = count;
}

// Check if empty
template <typename T>
bool Deque<T>::isEmpty() const {
    return count == 0;
}

// Dump entire array (for debugging)
template <typename T>
std::string Deque<T>::dumpArray() const {
    std::ostringstream out;

    for (int i = 0; i < capacity; i++) {
        out << data[i];
        if (i < capacity - 1) {
            out << " ";
        }
    }

    return out.str();
}

// List queue contents in order
template <typename T>
std::string Deque<T>::listQueue() const {
    std::ostringstream out;

    for (int i = 0; i < count; i++) {
        out << data[(left + i) % capacity];
        if (i < count - 1) {
            out << " ";
        }
    }

    return out.str();
}

// solveThink (unchanged)
template <typename T>
void Deque<T>::solveThink(int values[], int n) {
    for (int i = 0; i < n; i++) {
        addHead(values[i]);
    }
}

template <typename T>
void Deque<T>::clear() {
    left = 0;
    right = 0;
    count = 0;
}
// Explicit template instantiation (optional but recommended)
template class Deque<int>;
template class Deque<double>;