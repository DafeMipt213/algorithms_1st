#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

int parent(int index) { return (index - 1) / 2; }
int leftChild(int index) { return 2 * index + 1; }
int rightChild(int index) { return 2 * index + 2; }

void MinHeap::Push(int val) {
  heap.push_back(val);
  SiftUp(heap.size() - 1);
}

int MinHeap::Pop() {
  if (heap.empty()) {
    throw std::out_of_range("Empty heap");
  }
  int maxVal = heap[0];
  heap[0] = heap.back();
  heap.pop_back();
  SiftDown(0);
  return maxVal;
}

void MinHeap::SiftUp(int index) {
  while (index > 0 && heap[parent(index)] > heap[index]) {
    std::swap(heap[parent(index)], heap[index]);
    index = parent(index);
  }
}

void MinHeap::SiftDown(int index) {
  int minIndex = index;
  int left = leftChild(index);
  int right = rightChild(index);
  if (left < heap.size() && heap[left] < heap[minIndex]) {
    minIndex = left;
  }

  if (right < heap.size() && heap[right] < heap[minIndex]) {
    minIndex = right;
  }

  if (index != minIndex) {
    std::swap(heap[index], heap[minIndex]);
    SiftDown(minIndex);
  }
}