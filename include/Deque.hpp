#ifndef DEQUE_HPP
#define DEQUE_HPP

#include <stdexcept>
#include <sstream>
#include <string>

template <typename T>
class Deque {
private:
    int capacity;
    T* data;
    int left;
    int right;
    int count;

public:
    // constructors
    Deque();
    Deque(int initialCapacity);

    // destructor
    ~Deque();

    // core operations
    void addTail(const T& value);
    void addHead(const T& value);

    T removeHead();
    T removeTail();

    bool isEmpty() const;
    void clear();
    void resize();

    // debug
    std::string dumpArray() const;
    std::string listQueue() const;

    // your special function
    void solveThink(int values[], int n);
};

// ===============================
// IMPLEMENTATION SECTION
// ===============================

template <typename T>
Deque<T>::Deque()
    : capacity(10), data(new T[capacity]), left(0), right(0), count(0) {}

template <typename T>
Deque<T>::Deque(int initialCapacity)
    : capacity(initialCapacity), data(new T[initialCapacity]),
      left(0), right(0), count(0) {}

template <typename T>
Deque<T>::~Deque() {
    delete[] data;
}

template <typename T>
void Deque<T>::addTail(const T& value) {
    if (count == capacity) {
        resize();
    }
    data[right] = value;
    right = (right + 1) % capacity;
    count++;
}

template <typename T>
void Deque<T>::addHead(const T& value) {
    if (count == capacity) {
        resize();
    }
    left = ((left - 1) + capacity) % capacity;
    data[left] = value;
    count++;
}

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

template <typename T>
bool Deque<T>::isEmpty() const {
    return count == 0;
}

template <typename T>
void Deque<T>::clear() {
    left = 0;
    right = 0;
    count = 0;
}

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

template <typename T>
std::string Deque<T>::dumpArray() const {
    std::ostringstream out;
    for (int i = 0; i < capacity; i++) {
        out << data[i];
        if (i < capacity - 1) out << " ";
    }
    return out.str();
}

template <typename T>
std::string Deque<T>::listQueue() const {
    std::ostringstream out;
    for (int i = 0; i < count; i++) {
        out << data[(left + i) % capacity];
        if (i < count - 1) out << " ";
    }
    return out.str();
}

template <typename T>
void Deque<T>::solveThink(int values[], int n) {
    for (int i = 0; i < n; i++) {
        addHead(values[i]);
    }
}

#endif