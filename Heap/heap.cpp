#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Heap {
    vector <T> heap;
    bool type;  // 0 => MinHeap, 1 => MaxHeap
    int heapSize;

    Heap(int type) {
        this->type = type;
        heap.push_back(0);
        heapSize = 1;
    }

    bool compare (T ourData, T with);
    bool isEmpty();
    void heapify (int idx);
    T top();
    void push(T data);
    void pop();
};

int main () {

    Heap <char> h(1);

    h.push('a');
    h.push('x');
    h.push('t');
    h.push('q');
    h.push('h');
    h.push('k');
    h.push('l');

    while (not h.isEmpty()) {
        cout << h.top() << ' ';
        h.pop();
    }



    return 0;
}

template <typename T>
bool Heap<T> :: compare (T ourData, T with) {
    return (not type ? ourData < with : ourData > with); 
}

template <typename T>
bool Heap<T> :: isEmpty() {
    return (heap.size() <= 1);
}

template <typename T>
void Heap<T> :: heapify (int idx) {
    int rootIdx = idx;
    int firstChild = 2 * idx, secondChild = 2 * idx + 1;

    int swapIdx = idx;
    if (firstChild < heapSize and compare(heap[firstChild], heap[swapIdx])) {
        swapIdx = firstChild;
    }

    if (secondChild < heapSize and compare(heap[secondChild], heap[swapIdx])) {
        swapIdx = secondChild;
    }

    if (swapIdx == rootIdx)
        return;
    
    swap(heap[rootIdx], heap[swapIdx]);
    heapify(swapIdx);
}

template <typename T>
T Heap<T> :: top() {
    assert(heapSize > 1);
    return heap[1];
}

template <typename T>
void Heap<T> :: push(T data) {
    heapSize++;
    heap.push_back(data);

    int curLoc = heap.size() - 1;
    while (curLoc > 1) {
        int par = curLoc / 2;
        if (compare(heap[curLoc], heap[par])) {
            swap(heap[curLoc], heap[par]);
            curLoc = par;
        } else {
            break;
        }
    }
}

template <typename T>
void Heap<T> :: pop() {
    heapSize--;
    int k = heap.size() - 1;
    swap(heap[1], heap[k]);
    heap.pop_back();

    heapify(1);
}
