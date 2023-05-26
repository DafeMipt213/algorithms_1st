#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  auto result = data_.back();
  data_.pop_back();
  return result;
}

size_t Stack::Count() { return data_.size(); }

void MinStack::Push(int value) {
  data_.push_back(value);
  if ((minData_.size() == 0) || (minData_.back() >= value)) {
    minData_.push_back(value);
  }
}

int MinStack::Pop() {
  auto result = data_.back();
  if (result == minData_.back()) {
    minData_.pop_back();
  }
  data_.pop_back();
  return result;
}

size_t MinStack::Count() { return data_.size(); }

int MinStack::GetMin() { return minData_.back(); }