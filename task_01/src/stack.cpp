#include "stack.hpp"
#include <exception>
#include <algorithm>
#include <iostream>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if(data_.size() == 0)
  {
    throw std::range_error("can't delete the element of Stack, because it's empty");
  }
  auto result = data_[data_.size() - 1];
  data_.pop_back();
  return result;
}
int Stack::GetFirst() { return data_[data_.size() - 1]; }

void MinStack::Push(int value) {
  if (data_.size() != 0) {
    data_.push_back(value);
    if (min_stack_.GetFirst() >= value) {
      min_stack_.Push(value);
    }
  } else {
    data_.push_back(value);
    min_stack_.Push(value);
  }
}

int MinStack::Pop() {
  auto result = data_[data_.size() - 1];
  data_.pop_back();
  if (result == min_stack_.GetFirst()) {
    min_stack_.Pop();
  }
  return result;
}
int MinStack::GetFirst() { return data_[data_.size() - 1]; }
int MinStack::GetMin() { return min_stack_.GetFirst(); }