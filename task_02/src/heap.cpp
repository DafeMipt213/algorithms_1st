#include "heap.hpp"

#include <cmath>
#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int n) {
  data_.push_back(n);
  SiftUp();
}

void MinHeap::SiftUp() {
  size_t index = data_.size() - 1;
  int upper_index = index;
  while (upper_index >= 0) {
    upper_index = (index - 1) / 2;
    if (data_[upper_index] > data_[index])
      std::swap(data_[upper_index], data_[index]);
    else
      return;
  }
}

int MinHeap::Pop() {
  if (data_.empty())
    throw std::out_of_range("Empty heap");
  int result = data_[0];
  data_[0] = data_.back();
  data_.pop_back();
  SiftDown();
  return result;
}

void MinHeap::SiftDown() {
  if (data_.size() == 0)
    return;
  int index = 0;
  int minimal_index = 0;
  while (2 * index + 1 <= data_.size() - 1) {
    int left_child_index = 2 * index + 1;
    int right_child_index = 2 * index + 2;
    if (left_child_index == data_.size() - 1) {
      if (data_[index] > data_[left_child_index])
        std::swap(data_[index], data_[left_child_index]);
      return;
    } else {
      if (data_[left_child_index] < data_[right_child_index])
        minimal_index = left_child_index;
      else
        minimal_index = right_child_index;
      if (data_[index] > data_[minimal_index]) {
        std::swap(data_[index], data_[minimal_index]);
        index = minimal_index;
      } else
        return;
    }
  }
}

size_t MinHeap::Size() { return data_.size(); }
