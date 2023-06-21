#include "heap.hpp"

#include <cstddef>
#include <stdexcept>
#include <vector>

void MinHeap::Push(int n) {
  heap.push_back(n);
  SiftUp(heap.size() - 1);
}

int MinHeap::Pop() {
  if (heap.empty()) {
    throw std::out_of_range("heap is empty");
  }
  int min = heap[0];
  heap[0] = heap.back();
  heap.back() = min;
  heap.pop_back();
  SiftDown(0);
  return min;
}

size_t MinHeap::Size() { return heap.size(); }

void MinHeap::SiftDown(int i) {
  while (2 * i + 1 < heap.size()) {
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int j = left;
    if (right < heap.size() && heap[right] < heap[left]) j = right;
    if (heap[i] <= heap[j]) break;
    std::swap(heap[i], heap[j]);
    i = j;
  }
}

void MinHeap::SiftUp(int i) {
  int k = (i - 1) / 2;
  while (heap[i] < heap[k]) {
    k = (i - 1) / 2;
    std::swap(heap[i], heap[k]);
    i = k;
  }
}