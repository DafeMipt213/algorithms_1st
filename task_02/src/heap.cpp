#include "heap.hpp"

#include <cmath>
#include <cstddef>
#include <iostream>
#include <stdexcept>

// Constructors:
MinHeap::MinHeap() : data_{} {}

MinHeap::MinHeap(std::vector<int> vec) : data_{vec} {
  for (int i = data_.size() - 1; i >= 0; --i) Sift_up(i);
}

// Other functions:
void MinHeap::Push(int value) {
  data_.push_back(value);
  Sift_up(data_.size() - 1);
}

int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  auto result = data_[0];
  data_[0] = data_[data_.size() - 1];
  data_.pop_back();
  Sift_down(0);
  return result;
}

size_t MinHeap::Size() { return data_.size(); }

int MinHeap::Depth() { return ceil(log2(data_.size() + 1)); }

void MinHeap::Sift_up(int index) {
  if (data_.empty()) return;
  if (index < 0 || index >= data_.size())
    throw std::out_of_range("sift_up: Wrong index");
  int i = index;
  while (i > 0) {
    if (data_[i] < data_[parent_index(i)])
      std::swap(data_[i], data_[parent_index(i)]);
    i = parent_index(i);
  }
}

void MinHeap::Sift_down(int index) {
  if (data_.empty() || data_.size() == 1) return;
  if (index < 0 || index >= data_.size())
    throw std::out_of_range("sift_down: Wrong index");
  int i = index;
  while (i <= parent_index(data_.size() - 1)) {
    int min_child_index = 0;
    if (data_[left_child_index(i)] <= data_[right_child_index(i)])
      min_child_index = left_child_index(i);
    else
      min_child_index = right_child_index(i);
    if (data_[i] > data_[min_child_index])
      std::swap(data_[i], data_[min_child_index]);
    i = min_child_index;
  }
}

int MinHeap::parent_index(int index) {
  if (index <= 0 || index >= data_.size())
    throw std::out_of_range("parent_index: Wrong index");
  return (index - 1) / 2;
}

int MinHeap::left_child_index(int index) {
  if (index < 0 || index > parent_index(data_.size() - 1))
    throw std::out_of_range("left_child_index: Wrong index");
  return 2 * index + 1;
}

int MinHeap::right_child_index(int index) {
  if (index < 0 || index > parent_index(data_.size() - 1))
    throw std::out_of_range("right_child_index: Wrong index");
  if (2 * index + 2 < data_.size())
    return 2 * index + 2;
  else
    return 2 * index + 1;
}

void MinHeap::Print() {
  std::cout << "[ ";
  for (int i = 0; i < data_.size(); ++i) std::cout << data_[i] << ' ';
  std::cout << "] "
            << "depth: " << Depth() << std::endl;
}