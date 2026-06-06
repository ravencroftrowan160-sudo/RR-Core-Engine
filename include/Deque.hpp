//deque.hpp

#ifndef DEQUE_HPP
#define DEQUE_HPP
#include <string>

class Deque{
private:    
    int capacity;
    int* data;
    int left;
    int right;
    int count;


public:
    //constructor/destructor
    Deque();
    ~Deque();

    //need added
    void addTail(int value);
    void resize();
    int removeHead();
    bool isEmpty() const;
    Deque(int initialCapacity);
    std::string dumpArray() const;
    std::string listQueue() const;
    void addHead(int value);
    int removeTail();

    void solveThink(int values[], int n);
};

#endif