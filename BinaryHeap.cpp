#include <iostream>
#include <algorithm>

using namespace std;

class BinaryHeap {
    private:
    int capacity;
    int size;
    int* heap;

    public:
    BinaryHeap(int capacity) {
        this -> capacity = capacity+1;
        this -> size = 1;
        heap = new int[this -> capacity];
    }
    ~BinaryHeap() {
        delete[] heap;
    }

    void insert(int data) {
        if(size == capacity) {
            throw "Heap is full";
        }
        heap[size] = data;
        int  i = size;
        while(i>1 && heap[i/2]>heap[i]) {
            swap(heap[i/2], heap[i]);
        } size = size + 1;
    } 

    int deleteMin() {
        if (size == 1) {
            throw "Binary heap is empty";
        } 
        int minData = heap[1];
        heap[1] = heap[size-1];
        size = size - 1;
        int i = 1;
        while(true) {
            int minIndex = 1;
            if (2*i < size && heap[minIndex] > heap[2*i]) {
                minIndex = 2*i;
            }
            if (2*i+1 < size && heap[minIndex] > heap[2*i + 1 ]) {
                minIndex = 2*i+1;
            }
            if (minIndex == i) {
                break;
            }
            swap(heap[i], heap[minIndex]);
            i = minIndex;
        }
        return minData;
    }

}; 