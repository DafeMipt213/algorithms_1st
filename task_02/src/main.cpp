#include <iostream>
#include "heap.hpp"
using namespace std;

int main() { 
    MinHeap heap;
    heap.Push(5);
    for(int i = 0; i < heap.Size(); ++i) {
        cout << heap.heap[i] << endl;
    }
}
