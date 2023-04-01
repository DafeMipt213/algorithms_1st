#pragma once

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <vector>

template <typename T>
class MinHeap {
 public:
  void Push(T);
  T Pop();
  size_t Size();
  void Clear();
  T getMin();
  T getMax();

 private:
  void Siftup(T);
  void Siftdown();
  std::vector<T> maxValues;
  std::vector<T> data_;
};

template <typename T>
void MinHeap<T>::Siftup(T value) {
  int index = data_.size() - 1;
  T check;
  while (value < data_[(index - 1) / 2]) {
    check = data_[(index - 1) / 2];
    data_[(index - 1) / 2] = value;
    data_[index] = check;
    if (index == 0) {
      break;
    }
    index = (index - 1) / 2;
  }
}

template <typename T>
void MinHeap<T>::Siftdown() {
  T check{0};
  size_t index{0};
  while (
      (data_[index] > data_[2 * index + 1] && (2 * index + 1) < data_.size()) ||
      (data_[index] > data_[2 * index + 2] && (2 * index + 2) < data_.size())) {
    if (data_[2 * index + 1] < data_[2 * index + 2] ||
        (2 * index + 2) >= data_.size()) {
      check = data_[2 * index + 1];
      data_[2 * index + 1] = data_[index];
      data_[index] = check;
      index = 2 * index + 1;
    }

    else {
      check = data_[2 * index + 2];
      data_[2 * index + 2] = data_[index];
      data_[index] = check;
      index = 2 * index + 2;
    }
    if (data_.size() >= index) {
      break;
    }
  }
}

template <typename T>
void MinHeap<T>::Push(T value) {
  if (data_.size() == 0 || value >= maxValues.back())
    maxValues.push_back(value);
  data_.push_back(value);
  Siftup(value);
}

template <typename T>
T MinHeap<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  T result = data_.front();
  data_.front() = data_.back();
  T key = data_.back();
  if (key == maxValues.back()) maxValues.pop_back();
  data_.pop_back();
  Siftdown();
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
T MinHeap<T>::getMin() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  return data_.front();
}

template <typename T>
T MinHeap<T>::getMax() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  return maxValues.back();
}
