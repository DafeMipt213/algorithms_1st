#pragma once

#include <initializer_list>
#include <iostream>
#include <stdexcept>
#include <vector>

// can work with any types
template <typename T>
class Stack {
 public:
  Stack() = default;
  Stack(std::initializer_list<T> lst);
  Stack(std::vector<T> vec);

  void Push(T value);
  T Pop();
  T Get();

 private:
  std::vector<T> data_;
};

template <typename T>
class MinStack {
 public:
  MinStack() = default;
  MinStack(std::initializer_list<T> lst);
  MinStack(std::vector<T> vec);

  void Push(int value);
  T Pop();
  T GetMin();
  T Get();

 private:
  std::vector<T> data_;
  Stack<T> minValues_;
};

template <typename T>
MinStack<T>::MinStack(std::vector<T> vec) {
  if (!vec.empty()) {
    data_.push_back(vec[0]);
    minValues_.Push(vec[0]);
  }
  for (size_t i = 1; i < vec.size(); ++i) {
    data_.push_back(vec[i]);
    if (data_[i] < minValues_.Get())
      minValues_.Push(data_[i]);
    else
      minValues_.Push(minValues_.Get());
  }
}

template <typename T>
MinStack<T>::MinStack(std::initializer_list<T> lst) {
  for (size_t i = 0; i < lst.size(); ++i) data_.push_back(*(lst.begin() + i));
  if (!data_.empty()) minValues_.Push(data_[0]);
  for (size_t i = 1; i < data_.size(); ++i)
    minValues_.Push(std::min(data_[i], minValues_.Get()));
}

template <typename T>
void MinStack<T>::Push(int value) {
  data_.push_back(value);
  try {
    if (minValues_.Get() >= value)
      minValues_.Push(value);
    else
      minValues_.Push(minValues_.Get());
  } catch (...) {
    minValues_.Push(value);
  }
}

template <typename T>
T MinStack<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Stack is empty ");
  auto result = data_[data_.size() - 1];
  data_.pop_back();
  minValues_.Pop();
  return result;
}

template <typename T>
T MinStack<T>::GetMin() {
  auto result = minValues_.Get();
  return result;
}

template <typename T>
T MinStack<T>::Get() {
  if (data_.empty())
    throw std::out_of_range("Stack is empty ");
  else
    return data_[data_.size() - 1];
}

template <typename T>
Stack<T>::Stack(std::initializer_list<T> lst) {
  for (size_t i = 0; i < lst.size(); ++i) data_.push_back(*(lst.begin() + i));
}

template <typename T>
Stack<T>::Stack(std::vector<T> vec) {
  for (size_t i = 0; i < vec.size(); ++i) data_.push_back(vec[i]);
}

template <typename T>
void Stack<T>::Push(T value) {
  data_.push_back(value);
}

template <typename T>
T Stack<T>::Pop() {
  if (data_.empty()) throw std::out_of_range("Stack is empty ");
  auto result = data_[data_.size() - 1];
  data_.pop_back();
  return result;
}

template <typename T>
T Stack<T>::Get() {
  if (data_.empty())
    throw std::out_of_range("Stack is empty ");
  else
    return data_[data_.size() - 1];
}
