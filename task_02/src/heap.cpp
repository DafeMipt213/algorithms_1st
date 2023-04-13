#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int val) {
  heap.push_back(val);
  siftUp(heap.size() - 1);
}

int MinHeap::Pop() {
  if (heap.empty()) {
    throw std::out_of_range("Empty heap");
  }
  int maxVal = heap[0];
  heap[0] = heap.back();
  heap.pop_back();
  siftDown(0);
  return maxVal;
}
