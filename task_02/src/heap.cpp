#include "heap.hpp"

#include <math.h>

#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

void MinHeap::SiftUp(size_t index) {
  while (index > 0 && index < Size()) {
    size_t cur_index = (index - 1) / 2;

    if (data_[index] < data_[cur_index]) {
      std::swap(data_[index], data_[cur_index]);
    }

    index = cur_index;
  }
}

void MinHeap::SiftDown() {
  unsigned long cur = 0;

  if (Size() == 2) {
    if (data_[0] > data_[1]) std::swap(data_[0], data_[1]);
  }

  while (cur * 2 + 2 < Size()) {
    unsigned long left_child = 2 * cur + 1;
    unsigned long right_child = 2 * cur + 2;

    if (data_[left_child] < data_[right_child]) {
      std::swap(data_[cur], data_[left_child]);
      cur = left_child;
    } else if (data_[right_child] <= data_[left_child]) {
      std::swap(data_[cur], data_[right_child]);
      cur = right_child;
    }
  }
}

void MinHeap::Push(int value) {
  data_.push_back(value);
  SiftUp(Size() - 1);
}

int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");

  if (Size() == 1) {
    auto result = data_[0];
    data_.pop_back();
    return result;
  }

  auto result = data_[0];
  std::swap(data_[0], data_[Size() - 1]);
  data_.pop_back();
  SiftDown();
  return result;
}

size_t MinHeap::Size() { return data_.size(); }