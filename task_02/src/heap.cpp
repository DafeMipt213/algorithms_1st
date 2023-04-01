#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int n) { heap.push_back(n); }

int MinHeap::Pop() {
  int min = heap[0];
  heap[0] = heap[heap.size() - 1];
  // heap.size() = heap.size() - 1;
  SiftUp(0);
  return min;
}

size_t MinHeap::Size() { return heap.size(); }

void MinHeap::SiftDown(int i) {
  while (2 * i + 1 < heap.size()) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int j = left;
    if (right < heap.size() and heap[right] < heap[left]) j = right;
    if (heap[i] <= heap[j]) break;
    std::swap(heap[i], heap[j]);
    i = j;
  }
}

void MinHeap::SiftUp(int i) {
  while (heap[i] < heap[(i - 1) / 2]) {
    std::swap(heap[i], heap[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}