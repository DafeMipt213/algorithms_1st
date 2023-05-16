#pragma once

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T>
class MinHeap {
 public:
  void Push(T value);
  T Pop();
  size_t Size();

 private:
  std::vector<T> data_;
  void SiftUp(size_t index);
  void SiftDown(size_t index);
};

template <typename T>
void MinHeap<T>::Push(T value) {
  data_.push_back(value);
  this->SiftUp(this->Size() - 1);
}

template <typename T>
T MinHeap<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  auto result = data_[0];
  std::swap(data_[0], data_.back());
  data_.pop_back();
  if (!data_.empty()) this->SiftDown(0);
  return result;
}

template <typename T>
void MinHeap<T>::SiftUp(size_t index) {
  if (index == 0) return;
  size_t parent_index = (index - 1) / 2;
  if (parent_index < 0) return;
  T parent = data_[parent_index];
  T element = data_[index];
  if (parent > element) {
    std::swap(data_[parent_index], data_[index]);
    SiftUp(parent_index);
  } else
    return;
}

template <typename T>
void MinHeap<T>::SiftDown(size_t index) {
  size_t left_child_index = 2 * index + 1;
  size_t right_child_index = 2 * index + 2;
  size_t data_last_index = this->Size() - 1;
  T element = data_[index];

  if (left_child_index >
      data_last_index)  // left and right children don't exist
    return;

  T left_child = data_[left_child_index];
  if (right_child_index <= data_last_index) {
    T right_child = data_[right_child_index];
    size_t min_index = -1;
    if (left_child < right_child) {
      min_index = left_child_index;
    } else {
      min_index = right_child_index;
    }
    std::swap(data_[index], data_[min_index]);
    this->SiftDown(min_index);
  }

  else if (element > left_child)
    std::swap(data_[index], data_[left_child_index]);
}

template <typename T>
size_t MinHeap<T>::Size() {
  if (data_.empty()) return 0;
  return data_.size();
}
