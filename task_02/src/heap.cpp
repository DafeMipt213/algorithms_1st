#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

size_t Parent(size_t index) { return (index - 1) / 2; }
size_t LeftChild(size_t index) { return 2 * index + 1; }
size_t RightChild(size_t index) { return 2 * index + 2; }

void MinHeap::Push(int val) {
  heap.push_back(val);
  SiftUp(heap.size() - 1);
}

int MinHeap::Pop() {
  if (heap.empty()) {
    throw std::out_of_range("Empty heap");
  }
  int max_value = heap[0];
  heap[0] = heap.back();
  heap.pop_back();
  SiftDown(0);
  return max_value;
}

void MinHeap::SiftUp(int index) {
  while (index > 0 && heap[Parent(index)] > heap[index]) {
    std::swap(heap[Parent(index)], heap[index]);
    index = Parent(index);
  }
}

void MinHeap::SiftDown(int index) {
  int min_index = index;
  int left = LeftChild(index);
  int right = RightChild(index);
  if (left < heap.size() && heap[left] < heap[min_index]) {
    min_index = left;
  }

  if (right < heap.size() && heap[right] < heap[min_index]) {
    min_index = right;
  }

  if (index != min_index) {
    std::swap(heap[index], heap[min_index]);
    SiftDown(min_index);
  }
}
bool MinHeap::Empty() const { return heap.empty(); }
size_t MinHeap::Size() const { return heap.size(); }