#include "heap.hpp"
#include <stdexcept>

void MinHeap::Push(int n) {
    h.push_back(n);
    size_t counter = HeapSize;
    size_t parent = (HeapSize - 1) / 2;
    while (parent >= 0 && counter > 0) {
        if (h[counter] < h[parent]) {
            int temp = h[counter];
            h[counter] = h[parent];
            h[parent] = temp;
        }
        counter = parent;
        parent = (counter - 1) / 2;
    }
    ++HeapSize;
}

void MinHeap::Upd_Heap(size_t i) {
    size_t left = 2 * i + 1, right = 2 * i +2;
    int value;
    if (left < HeapSize) {
        if (h[i] > h[left]) {
            value = h[i];
            h[i] = h[left];
            h[left] = value;
            Upd_Heap(left);
        }
    }
    if (right < HeapSize) {
        if (h[i] > h[left]) {
            value = h[i];
            h[i] = h[right];
            h[right] = value;
            Upd_Heap(right);
        }
    }
}

int MinHeap::Pop() {
    if (HeapSize == 0) throw std::out_of_range("Empty heap");
    int result = h[0];
    h[0] = h[HeapSize - 1];
    --HeapSize;
    Upd_Heap(0);
    return result;
}

size_t MinHeap::Size() const { return HeapSize;}