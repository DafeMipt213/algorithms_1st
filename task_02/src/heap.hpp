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
  void ShiftDown(size_t index);
  void ShiftUp(size_t index);

 private:
  std::vector<T> data_;
};

template <typename T>
void MinHeap<T>::Push(T value) {
  data_.push_back(value);
  ShiftUp(data_.size() - 1);
}

template <typename T>
void MinHeap<T>::ShiftUp(size_t index) {
  if (data_[index] < data_[index / 2]) {
    std::swap(data_[index], data_[index / 2]);
    ShiftUp(index / 2);
  } else
    return;
}

template <typename T>
void MinHeap<T>::ShiftDown(size_t index) {
  size_t leftChild = 2 * index + 1;
  size_t rightChild = 2 * index + 2;
  if (leftChild > data_.size() - 1 || index > data_.size())
    return;
  else {
    if (data_[index] == data_[leftChild] &&
        data_[leftChild] == data_[rightChild])
      return;
    else if (data_[index] > data_[leftChild] &&
             data_[leftChild] <= data_[rightChild]) {
      std::swap(data_[leftChild], data_[index]);
      ShiftDown(leftChild);
    } else if (data_[index] > data_[leftChild] &&
               data_[leftChild] > data_[rightChild]) {
      std::swap(data_[rightChild], data_[index]);
      ShiftDown(rightChild);
    }
  }
}

template <typename T>
T MinHeap<T>::Pop() {
  if (!data_.size()) throw std::out_of_range("Empty heap");
  T result = data_[0];
  data_[0] = data_.back();
  data_.pop_back();
  ShiftDown(0);
  return result;
}

template <typename T>
size_t MinHeap<T>::Size() {
  return data_.size();
}