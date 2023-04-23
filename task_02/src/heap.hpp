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
  void Clear();
  T GetMin();
  T GetMax();

 private:
  void SiftUp(T value);
  void SiftDown();
  std::vector<T> max_values_;
  std::vector<T> data_;
};

template <typename T>
void MinHeap<T>::SiftUp(T value) {
  int index = data_.size() - 1;
  int swap_index = (index - 1) / 2;
  while (value < data_[swap_index]) {
    if (index == 0) break;
    data_[index] = data_[swap_index];
    data_[swap_index] = value;
    index = swap_index;
    swap_index = (index - 1) / 2;
  }
}

template <typename T>
void MinHeap<T>::SiftDown() {
  int index = 0, swap_index_1 = 2 * index + 1, swap_index_2 = 2 * index + 2;
  while ((data_[index] > data_[swap_index_1] && swap_index_1 < data_.size()) ||
         (data_[index] > data_[swap_index_2] && swap_index_2 < data_.size())) {
    if (data_[swap_index_1] < data_[swap_index_2] ||
        swap_index_2 >= data_.size()) {
      std::swap(data_[index], data_[swap_index_1]);
      index = swap_index_1;
      swap_index_1 = 2 * index + 1;
    }

    else {
      std::swap(data_[index], data_[swap_index_2]);
      index = swap_index_2;
      swap_index_2 = 2 * index + 2;
    }
    if (data_.size() >= index) {
      break;
    }
  }
}

template <typename T>
void MinHeap<T>::Push(T value) {
  if (data_.size() == 0 || value >= max_values_.back())
    max_values_.push_back(value);
  data_.push_back(value);
  SiftUp(value);
}

template <typename T>
T MinHeap<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  T result = data_.front();
  data_.front() = data_.back();
  T key = data_.back();
  if (key == max_values_.back()) max_values_.pop_back();
  data_.pop_back();
  SiftDown();
  return result;
}

template <typename T>
size_t MinHeap<T>::Size() {
  return data_.size();
}

template <typename T>
void MinHeap<T>::Clear() {
  return data_.clear();
}

template <typename T>
T MinHeap<T>::GetMin() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  return data_.front();
}

template <typename T>
T MinHeap<T>::GetMax() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  return max_values_.back();
}
