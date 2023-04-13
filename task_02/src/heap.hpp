#pragma once

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

class MinHeap {
 private:
  std::vector<int> heap;

  int parent(int index) { return (index - 1) / 2; }
  int leftChild(int index) { return 2 * index + 1; }
  int rightChild(int index) { return 2 * index + 2; }

  void siftUp(int index) {
    while (index > 0 && heap[parent(index)] > heap[index]) {
      std::swap(heap[parent(index)], heap[index]);
      index = parent(index);
    }
  }

  void siftDown(int index) {
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
      siftDown(minIndex);
    }
  }

 public:
  void Push(int val);
  int Pop();
  bool empty() const { return heap.empty(); }
  int size() const { return heap.size(); }
};
