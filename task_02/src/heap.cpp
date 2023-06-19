#include "heap.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

void MinHeap::Push(int n) {
  array.push_back(n);
  SiftUp(array.size() - 1);
}

int MinHeap::Pop() {
  if (array.empty()) throw std::out_of_range("Empty heap");
  int elem = array[0];
  array[0] = array[array.size() - 1];
  array.pop_back();
  SiftDown(0);
  return elem;
}

size_t MinHeap::Size() { return array.size(); }

void MinHeap::SiftUp(size_t index) {
  if (index > 0) {
    size_t parent_index = (index - 1) / 2;
    if (array[parent_index] > array[index]) {
      std::swap(array[parent_index], array[index]);
    }
    SiftUp(parent_index);
  }
  return;
}
void MinHeap::SiftDown(size_t index) {
  if (array.size() == 0) return;
  if ((2 * index + 1) < (array.size())) {
    size_t left_child_index = 2 * index + 1;
    size_t right_child_index = 2 * index + 2;
    size_t next_child_index = left_child_index;
    if (right_child_index < (array.size())) {
      if (array[left_child_index] > array[right_child_index])
        next_child_index = right_child_index;
    }
    int child = array[next_child_index];
    if (array[index] < child)
      return;
    else {
      array[next_child_index] = array[index];
      array[index] = child;
      SiftDown(next_child_index);
    }
  };
}
