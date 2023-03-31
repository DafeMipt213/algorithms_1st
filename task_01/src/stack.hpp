#pragma once

//#include <stack>
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

// can work with numeric types
template <typename T>
class MinStack;

// specialization for int
template <>
class MinStack<int> {
 public:
  MinStack() = default;
  MinStack(std::initializer_list<int> lst) {
    for (size_t i = 0; i < lst.size(); ++i) data_.push_back(*(lst.begin() + i));
    if (!data_.empty()) minValues_.Push(data_[0]);
    for (size_t i = 1; i < data_.size(); ++i) {
      if (data_[i] < minValues_.Get())
        minValues_.Push(data_[i]);
      else
        minValues_.Push(minValues_.Get());
    }
  }
  MinStack(std::vector<int> vec) {
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

  void Push(int value) {
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

  int Pop() {
    if (data_.empty()) throw std::out_of_range("Stack is empty ");
    auto result = data_[data_.size() - 1];
    data_.pop_back();
    minValues_.Pop();
    return result;
  }

  int GetMin() {
    auto result = minValues_.Get();
    return result;
  }

  int Get() {
    if (data_.empty())
      throw std::out_of_range("Stack is empty ");
    else
      return data_[data_.size() - 1];
  }

 private:
  std::vector<int> data_;
  Stack<int> minValues_;
};

// specialization for double
template <>
class MinStack<double> {
 public:
  MinStack() = default;
  MinStack(std::initializer_list<double> lst) {
    for (size_t i = 0; i < lst.size(); ++i) data_.push_back(*(lst.begin() + i));
    if (!data_.empty()) minValues_.Push(data_[0]);
    for (size_t i = 1; i < data_.size(); ++i) {
      if (data_[i] < minValues_.Get())
        minValues_.Push(data_[i]);
      else
        minValues_.Push(minValues_.Get());
    }
  }
  MinStack(std::vector<double> vec) {
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

  void Push(double value) {
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

  double Pop() {
    if (data_.empty()) throw std::out_of_range("Stack is empty ");
    auto result = data_[data_.size() - 1];
    data_.pop_back();
    minValues_.Pop();
    return result;
  }

  double GetMin() {
    double result = minValues_.Get();
    return result;
  }

  double Get() {
    if (data_.empty())
      throw std::out_of_range("Stack is empty ");
    else
      return data_[data_.size() - 1];
  }

 private:
  std::vector<double> data_;
  Stack<double> minValues_;
};

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
