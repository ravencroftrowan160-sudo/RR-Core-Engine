#ifndef HEAP_HPP
#define HEAP_HPP

class Heap{
private:
    int* arr;      // the array
    int capacity;  // how many slots allocated
    int size;      // how many items currently in heap

    void resize();
    void bubbleUp(int index);
    void trickleDown(int index);
public:
    Heap(int cap = 10);
    ~Heap();

    void addItem(int val);
    int getItem();
};
#endif