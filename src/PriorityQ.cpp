#include "PriorityQ.hpp"

PriorityQ::PriorityQ(int capacity)
    : heap(capacity)   // initialize the internal heap
{
}

PriorityQ::~PriorityQ() {
    // Nothing to do here.
    // The Heap member's destructor will run automatically.
}

void PriorityQ::addItem(int val) {
    heap.addItem(val);
}

int PriorityQ::getItem() {
    return heap.getItem();
}