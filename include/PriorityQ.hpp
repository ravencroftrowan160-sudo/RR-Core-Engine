#ifndef PRIORITYQ_HPP
#define PRIORITYQ_HPP
#include "Heap.hpp"

class PriorityQ{
private:
    Heap heap;

public:
    PriorityQ(int cap = 10);
    ~PriorityQ();
    
    void addItem(int val);
    int getItem();
};
#endif