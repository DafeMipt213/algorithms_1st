#include "heap.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

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

void MinHeap::SiftUp(int index) {
  if (index > 0) {
    int parent = array[(index - 1) / 2];
    if (parent > array[index]) {
      array[(index - 1) / 2] = array[index];
      array[index] = parent;
    }
    SiftUp((index - 1) / 2);
  }
  return;
}
void MinHeap::SiftDown(int index) {
  if (array.size() == 0) return;
  if ((2 * index + 1) < (array.size())) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    int next_child_index = left_child_index;
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
