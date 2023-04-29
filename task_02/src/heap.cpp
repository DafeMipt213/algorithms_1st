#include "heap.hpp"

#include <math.h>

#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

void MinHeap::SiftUp(size_t index) {
  while (index > 0 && index < Size()) {
    if (data_[index] < data_[(index - 1) / 2]) {
      std::swap(data_[index], data_[(index - 1) / 2]);
    }

    index = (index - 1) / 2;
  }
}

void MinHeap::SiftDown() {
  unsigned long cur = 0;

  if (Size() == 2) {
    if (data_[0] > data_[1]) std::swap(data_[0], data_[1]);
  }

  while (cur * 2 + 2 < Size()) {
    unsigned long lChild = 2 * cur + 1;
    unsigned long rChild = 2 * cur + 2;

    if (2 * cur < Size()) {
      if (data_[lChild] < data_[rChild]) {
        std::swap(data_[cur], data_[lChild]);
        cur = lChild;
      } else if (data_[rChild] <= data_[lChild]) {
        std::swap(data_[cur], data_[rChild]);
        cur = rChild;
      }
    } else {
      if (lChild < Size()) {
        std::swap(data_[cur], data_[lChild]);
        cur = lChild;
      } else
        return;
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
