#pragma once

#include <cstddef>
#include <functional>
#include <iostream>
#include <queue>
#include <stdexcept>
#include <vector>

template <typename T>
class MinHeap {
 public:
  void Push(T value);

  T Pop();

  size_t Size() { return data_.size(); }

  void Show() {
    for (const auto& i : data_) std::cout << i << ' ';
  }

 private:
  void SiftUp(int index);
  void SiftDown(int index);

  std::vector<T> data_;
};

template <typename T>
void MinHeap<T>::Push(T value) {
  data_.push_back(value);
  SiftUp((int)data_.size() - 1);
}

template <typename T>
T MinHeap<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  auto result = data_[0];
  data_[0] = data_.back();
  data_.pop_back();
  if (!data_.empty()) SiftDown(0);
  return result;
}

template <typename T>
void MinHeap<T>::SiftUp(int index) {
  if (!index) return;
  T child = data_[index];
  T parent = data_[(index - 1) / 2];
  if (child < parent) {
    std::swap(data_[index], data_[(index - 1) / 2]);
    SiftUp((index - 1) / 2);
  }
}

template <typename T>
void MinHeap<T>::SiftDown(int index) {
  int left_child_index = 2 * index + 1;
  int right_child_index = 2 * index + 2;
  T parent = data_[index];
  if (left_child_index > data_.size() - 1) return;
  if (right_child_index > data_.size() - 1) {
    if (parent > data_[left_child_index]) {
      std::swap(data_[index], data_[left_child_index]);
    }
    return;
  }
  if (parent > std::min(data_[left_child_index], data_[right_child_index])) {
    if (data_[left_child_index] > data_[right_child_index]) {
      std::swap(data_[index], data_[right_child_index]);
      SiftDown(right_child_index);
    } else {
      std::swap(data_[index], data_[left_child_index]);
      SiftDown(left_child_index);
    }
  }
  return;
}