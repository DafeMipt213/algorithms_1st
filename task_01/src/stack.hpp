#pragma once

#include <stdexcept>
#include <vector>
#include <cstddef>


template <typename T>
class Stack {
 public:
  void Push(T value);
  T Pop();
  T Back();
  int Size();
  void Clear();

 private:
  size_t size{0};
  std::vector<T> data_;
};

template <typename T>
void Stack<T>::Push(T value){ 
  data_.push_back(value); 
  ++size;
}

template <typename T>
T Stack<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty stack");
  T result = data_.back();
  data_.pop_back();
  --size;
  return result;
}

template <typename T>
T Stack<T>::Back() {
  return data_[size-1];
}

template <typename T>
int Stack<T>::Size() {
  return size;
}

template <typename T>
void Stack<T>::Clear() {
  size = 0;
  data_.clear();
}






template <typename T>
class MinStack {
 public:
  void Push(T value);
  T Pop();
  T GetMin();
  T Back();
  int Size();
  void Clear();

 private:
  size_t size{0};
  std::vector<T> minValues;
  std::vector<T> data_;
};

template <typename T>
void MinStack<T>::Push(T value) { 
  if (size == 0 || minValues.back() >= value)
    minValues.push_back(value);

  data_.push_back(value); 
  ++size;
}

template <typename T>
T MinStack<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  T result = data_.back();
  data_.pop_back();

  if (result == minValues.back())
    minValues.pop_back();

  --size;
  return result;
}

template <typename T>
T MinStack<T>::GetMin() { 
  return minValues.back();  
}

template <typename T>
T MinStack<T>::Back() {
  return data_[size-1];
}

template <typename T>
int MinStack<T>::Size() {
  return size;
}

template <typename T>
void MinStack<T>::Clear() {
  size = 0;
  data_.clear();
}
