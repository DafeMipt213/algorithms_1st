#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int n) {
  data_.push_back(n);
  SiftUp(data_.size()-1);
  }

int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  auto result = data_[0];
  data_[0] = data_[data_.size()-1];
  data_.pop_back();
  if (!data_.empty()) SiftDown(0);
  return result;
}

size_t MinHeap::Size() { return data_.size(); }

void MinHeap::SiftUp(int index){
  if (!index) return;
  int child = data_[index];
  int parent = data_[(index-1)/2];
  if (child < parent){
    std::swap(data_[index], data_[(index-1)/2]);
    SiftUp((index-1)/2);
  }
}

void MinHeap::SiftDown(int index){
  int left_child_index = 2*index + 1;
  int right_child_index = 2*index + 2;
  int parent = data_[index];
  if (left_child_index > data_.size()-1) return;
  if (right_child_index > data_.size()-1) {
    if (parent > data_[left_child_index]) {
      std::swap(data_[index], data_[left_child_index]);
    }
    return;
  }
  if (parent > std::min(data_[left_child_index], data_[right_child_index])) {
    if (data_[left_child_index] > data_[right_child_index]) {
      std::swap(data_[index], data_[right_child_index]);
      SiftDown(right_child_index);
    }
    else {
      std::swap(data_[index], data_[left_child_index]);
      SiftDown(left_child_index);
    }
  }
  return;
}