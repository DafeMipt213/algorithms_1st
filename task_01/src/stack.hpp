#pragma once

#include <stack>
#include <type_traits>
#include <vector>

template <typename T,
          typename =
              typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Stack {
 public:
  void Push(T value);
  T Pop();
  bool IsEmpty();
  T Top();

 private:
  std::vector<T> data_;
};

template <typename T,
          typename =
              typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class MinStack {
 public:
  void Push(T value);
  T Pop();
  T GetMin();

 private:
  Stack<T> data_;
  Stack<T> minData_;
};

template <typename T, typename A>
void Stack<T, A>::Push(T value) {
  data_.push_back(value);
}

template <typename T, typename A>
T Stack<T, A>::Pop() {
  auto result = data_.back();
  data_.pop_back();
  return result;
}

template <typename T, typename A>
T MinStack<T, A>::Pop() {
  minData_.Pop();
  return data_.Pop();
}

template <typename T, typename A>
bool Stack<T, A>::IsEmpty() {
  return data_.empty();
}

template <typename T, typename A>
T Stack<T, A>::Top() {
  return data_.back();
}

template <typename T, typename A>
void MinStack<T, A>::Push(T value) {
  if (data_.IsEmpty()) {
    minData_.Push(value);
  } else {
    auto minValue = std::min(value, GetMin());
    minData_.Push(minValue);
  }
  data_.Push(value);
}

template <typename T, typename A>
T MinStack<T, A>::GetMin() {
  auto min_elem = minData_.Top();
  return min_elem;
}