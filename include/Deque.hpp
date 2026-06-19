//deque.hpp

#ifndef DEQUE_HPP
#define DEQUE_HPP
#include <string>

template <typename T>
class Deque{
private:    
    int capacity;
    T* data;
    int left;
    int right;
    int count;


public:
    //constructor/destructor
    Deque();
    ~Deque();

    //need added
    void addTail(const T& value);
    void addHead(const T& value);

    T removeHead();
    T removeTail();

    void resize();
    bool isEmpty() const;

    Deque(int initialCapacity);

    std::string dumpArray() const;
    std::string listQueue() const;
    void clear(); 
    
    void solveThink(int values[], int n);
};

#endif