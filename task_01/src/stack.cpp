#include "stack.hpp"

#include <algorithm>
#include <exception>
#include <iostream>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty Stack");
  int result = data_.back();
  data_.erase(data_.end() - 1);
  return result;
}

void MinStack::Push(int value) {
  if (!data_.empty()) {
    int min_num = std::min(value, data_.back().second);
    data_.push_back(std::pair<int, int>(value, min_num));
  } else {
    data_.push_back(std::pair<int, int>(value, value));
  }
}

int MinStack::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty MinStack");
  int result = data_.back().first;
  data_.erase(data_.end() - 1);
  return result;
}

int MinStack::GetMin() {
  if (data_.empty()) throw std::out_of_range("Empty MinStack");
  return data_.back().second;
}