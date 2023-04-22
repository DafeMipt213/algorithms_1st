#include "heap.hpp"

#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

// Constructors:
MinHeap::MinHeap() : data_{} {}

MinHeap::MinHeap(std::vector<int> vec) : data_{std::move(vec)} {
  for (auto i = data_.size() - 1; i >= 0; --i) SiftUp(i);
}

// Other functions:
void MinHeap::Push(int value) {
  data_.push_back(value);
  SiftUp(data_.size() - 1);
}

int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  auto result = data_[0];
  data_[0] = data_.back();
  data_.pop_back();
  SiftDown(0);
  return result;
}

size_t MinHeap::Size() { return data_.size(); }

int MinHeap::Depth() { return ceil(log2(data_.size() + 1)); }

void MinHeap::SiftUp(size_t index) {
  if (data_.empty()) return;
  if (index < 0 || index >= data_.size())
    throw std::out_of_range("SiftUp: Wrong index");
  int i = index;
  while (i > 0) {
    if (data_[i] < data_[GetParentIndex(i)])
      std::swap(data_[i], data_[GetParentIndex(i)]);
    i = GetParentIndex(i);
  }
}

void MinHeap::SiftDown(size_t index) {
  if (data_.empty() || data_.size() == 1) return;
  if (index < 0 || index >= data_.size())
    throw std::out_of_range("SiftUp: Wrong index");
  int i = index;
  while (i <= GetParentIndex(data_.size() - 1)) {
    int min_child_index = MinChildIndex(i);
    if (data_[i] > data_[min_child_index])
      std::swap(data_[i], data_[min_child_index]);
    i = min_child_index;
  }
}

size_t MinHeap::GetParentIndex(size_t index) {
  if (index <= 0 || index >= data_.size())
    throw std::out_of_range("GetParentIndex: Wrong index");
  return (index - 1) / 2;
}

size_t MinHeap::GetLeftChildIndex(size_t index) {
  if (index < 0 || index > GetParentIndex(data_.size() - 1))
    throw std::out_of_range("GetLeftChildIndex: Wrong index");
  return 2 * index + 1;
}

size_t MinHeap::GetRightChildIndex(size_t index) {
  if (index < 0 || index > GetParentIndex(data_.size() - 1))
    throw std::out_of_range("GetRightChildIndex: Wrong index");
  if (2 * index + 2 < data_.size())
    return 2 * index + 2;
  else
    return 2 * index + 1;
}

void MinHeap::Print() {
  std::cout << "[ ";
  for (auto i : data_) std::cout << i << ' ';
  std::cout << "] "
            << "depth: " << Depth() << std::endl;
}

size_t MinHeap::MinChildIndex(size_t i) {
  int min_child_index = 0;
  if (data_[GetLeftChildIndex(i)] <= data_[GetRightChildIndex(i)])
    min_child_index = GetLeftChildIndex(i);
  else
    min_child_index = GetRightChildIndex(i);
  return min_child_index;
}