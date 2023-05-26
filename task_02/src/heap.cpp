#include "heap.hpp"

#include <cmath>
#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int n) {
  data_.push_back(n);
  SiftUp();
}

void MinHeap::SiftUp() { //Fixed
  size_t index = data_.size() - 1;
  int upperIndex = index;
  while (upperIndex >= 0) {
    upperIndex = (index - 1) / 2;
    if (data_[upperIndex] > data_[index])
      std::swap(data_[upperIndex], data_[index]);
    else
      return;
  }
}

int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  int result = data_[0];
  data_[0] = data_.back();
  data_.pop_back();
  SiftDown();
  return result;
}

void MinHeap::SiftDown() {
  if (data_.size() == 0) return;
  int index = 0;
  int minimal_index = 0;
  while (2 * index + 1 <= data_.size() - 1) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    if (leftChildIndex == data_.size() - 1) {
      if (data_[index] > data_[leftChildIndex]) 
        std::swap(data_[index], data_[leftChildIndex]);
      return;
    } else {
      if (data_[leftChildIndex] < data_[rightChildIndex])
        minimal_index = leftChildIndex;
      else
        minimal_index = rightChildIndex;
      if (data_[index] > data_[minimal_index]) {
        std::swap(data_[index], data_[minimal_index]);
        index = minimal_index;
      } else
        return;
    }
  }
}

size_t MinHeap::Size() { return data_.size(); }
