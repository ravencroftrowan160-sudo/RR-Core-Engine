//deque.cpp

#include "Deque.hpp"
#include <stdexcept>
#include <sstream>
//constructor
Deque::Deque():capacity(10), data(new int [capacity]), left(0), right(0), count(0){

}

//destructor
Deque::~Deque(){
    delete[] data;
}

//now addTail(); should add a value to the end of the Deque
void Deque::addTail(int value){
    if(count == capacity){
        resize();
    }

    data[right] = value;

    right = (right + 1) % capacity;
    count++;
}

//resize(); should resize capacity to be twice as large
void Deque::resize(){
    int newCapacity = capacity * 2;

    int* newArray = new int[newCapacity];

    for(int i = 0; i < count; i++){
        newArray[i] = data[(left + i) % capacity];
    }

    delete[] data;

    data = newArray;
    capacity = newCapacity;

    left = 0;
    right = count;
}

//removeHead();  
int Deque::removeHead(){
    if(isEmpty()){
        throw std::out_of_range("Array is empty in removeHead");
    }

    int savedValue = data[left];

    left = (left + 1) % capacity;

    count = count - 1;

    return savedValue;
}

//isEmpty(); returns True if yes,
bool Deque::isEmpty() const{
    if(count == 0){
        return true;
    }

    return false;
}

Deque::Deque(int initialCapacity) : capacity(initialCapacity), data(new int[initialCapacity]), left(0), right(0), count(0){

}

//dumpArray(); 
std::string Deque::dumpArray() const {
    std::ostringstream out;

    for (int i = 0; i < capacity; i++) {
        out << data[i];
        if (i < capacity - 1) {
            out << " ";
        }
    }

    return out.str();
}

std::string Deque::listQueue() const {
    std::ostringstream out;

    for (int i = 0; i < count; i++) {
        out << data[(left + i) % capacity];
        if (i < count - 1) {
            out << " ";
        }
    }

    return out.str();
}

void Deque::addHead(int value){
    if(count == capacity){
        resize();
    }

    //move left backwards one position, wrapping if needed
    left = ((left - 1) + capacity) % capacity;

    //store the new value at the left position
    data[left] = value;

    //increase the number of stored items
    count++;
}

//removeTail(), same as removeHead() but returning the value at tail
int Deque::removeTail(){
    if(isEmpty()){
        throw std::out_of_range("Array is empty in removeTail");
    }

    right = ((right - 1) + capacity) % capacity;
    int savedValue = data[right];

    count = count - 1;

    return savedValue;
}

//solveThink(); reverse the array
void Deque::solveThink(int values[], int n){
    for(int i = 0; i < n; i++){
        addHead(values[i]);
    }
}