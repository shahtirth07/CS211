#include <iostream>

using namespace std;

class PriorityQueue {
    private:
    int arr[4];
    int size = 0;

    public:
    void enqueue (int x) {
        if(size == 4) {
            throw "The size of the priority queue is full";
        }
        int i = size;
        arr[i] = x;
        while(i > 0) {
            i = i-1;
            if(arr[i] > arr[i+1]) {
                swap(arr[i+1], arr[i]);
            }
        }
        size = size+1;
    }

    int dequeue() {
        if (size == 0) {
            throw "Priority Queue is empty, cannot call dequeue";
        }
        else {
            int ret = arr[size-1];
            size = size-1;
            return ret;
        }
    }
};

int main() {
    PriorityQueue *pq = new PriorityQueue();
    pq->enqueue(100);
    pq->enqueue(1);
    pq->enqueue(101);
    pq->enqueue(2);

    cout << pq->dequeue() << endl;
    cout << pq->dequeue() << endl;
    cout << pq->dequeue() << endl;
    cout << pq->dequeue() << endl;

}