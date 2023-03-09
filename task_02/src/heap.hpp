#pragma once

#include <cstddef>
#include <functional>
#include <vector>
#include <stdexcept>

template <typename T>
class MinHeap {
 public:
  void Push(T value);
  T Pop();
  size_t Size();

 private:
  std::vector<T> data_;
  void SiftUp(int index);
  void SiftDown(int index);
};

template<typename T>
void MinHeap<T>::Push(T value) { 
  data_.push_back(value);
  this->SiftUp(this->Size() - 1);
}

template<typename T>
T MinHeap<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  auto result = data_[0];
  std::swap(data_[0], data_[this->Size() - 1]);
  data_.pop_back();
  this->SiftDown(0);
  return result;
}

template<typename T>
void MinHeap<T>::SiftUp(int index) {
  if (index == 0)
    return;
  int parent_ind = (index - 1) / 2; 
  if (parent_ind < 0)
    return;
  T parent = data_[parent_ind];
  T element = data_[index];
  if (parent > element) {
    std::swap(data_[parent_ind], data_[index]);
    SiftUp(parent_ind); 
  }
  else
    return;
}

template<typename T>
void MinHeap<T>::SiftDown(int index) {
  int left_child_ind = 2 * index + 1;
  int right_child_ind = 2 * index + 2;
  int data_last_ind = this->Size() - 1;
  T element = data_[index];

  if (left_child_ind > data_last_ind) // left and right children don't exist
    return;

  T left_child = data_[left_child_ind];
  if (right_child_ind <= data_last_ind) {
    T right_child = data_[right_child_ind];
    int min_ind = -1;
    if (left_child < right_child)
      min_ind = left_child_ind;
    else
      min_ind = right_child_ind;
      
    std::swap(data_[index], data_[min_ind]);
    this->SiftDown(min_ind);
    }

  else
    if (element > left_child)
      std::swap(data_[index], data_[left_child_ind]);
}

template<typename T>
size_t MinHeap<T>::Size() { return data_.size(); }
