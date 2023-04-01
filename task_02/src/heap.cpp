#include "heap.hpp"

#include <math.h>

#include <array>
#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

void MinHeap::siftUp(unsigned int ind) {
  while (ind > 0 && ind < Size()) {
    if (data_[ind] < data_[(ind - 1) / 2]) {
      std::swap(data_[ind], data_[(ind - 1) / 2]);
    }

    ind = (ind - 1) / 2;
  }
}

void MinHeap::siftDown() {
  unsigned long i = 0;

  if (Size() == 2) {
    if (data_[0] > data_[1]) {
      std::swap(data_[0], data_[1]);
    }
  }

  while (i * 2 + 2 < Size()) {
    if (2 * i < Size()) {
      if (data_[2 * i + 1] < data_[2 * i + 2]) {
        std::swap(data_[i], data_[2 * i + 1]);
        i = 2 * i + 1;

      } else if (data_[2 * i + 1] >= data_[2 * i + 2]) {
        std::swap(data_[i], data_[2 * i + 2]);
        i = 2 * i + 2;
      }
    }

    else {
      if (2 * i + 1 < Size()) {
        std::swap(data_[i], data_[2 * i + 1]);
        i = 2 * i + 1;
      }

      else {
        return;
      }
    }
  }
}

void MinHeap::Push(int n) {
  data_.push_back(n);
  siftUp(Size() - 1);
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
  siftDown();
  return result;
}

size_t MinHeap::Size() { return data_.size(); }
