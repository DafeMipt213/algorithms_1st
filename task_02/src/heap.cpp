#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::SiftUp(int i) {        // (i - 1) / 2 -- Parent i
  if (i && data_[(i - 1) / 2] > data_[i]) {
    int buffer = data_[i];
    data_[i] = data_[(i - 1) / 2];
    data_[(i - 1) / 2] = buffer;
    SiftUp((i - 1) / 2);
  }
}

void MinHeap::SiftDown(int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;
  int smallest = i;
 
  if (left < Size() && data_[left] < data_[i]) {
    smallest = left;
  }
 
  if (right < Size() && data_[right] < data_[smallest]) {
    smallest = right;
  }
 
  if (smallest != i) {
    int buffer = data_[i];
    data_[i] = data_[smallest];
    data_[smallest] = buffer;
    SiftDown(smallest);
  }
}

void MinHeap::Push(int n) { 
  data_.push_back(n);
  SiftUp(int(Size()) - 1);
}

int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  int result = data_[0];
  data_[0] = data_.back();
  data_.pop_back();
  SiftDown(0);
  return result;
}

size_t MinHeap::Size() { return data_.size(); }
