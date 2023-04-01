#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  auto result = data_.back();
  data_.pop_back();
  return result;
}

bool Stack::IsEmpty() { return !data_.size(); }

void MinStack::Push(int value) {
  if (data_.IsEmpty()) {
    minData_.Push(value);
  } else {
    int minValue = std::min(value, GetMin());
    minData_.Push(minValue);
  }
  data_.Push(value);
}

int MinStack::Pop() {
  minData_.Pop();
  return data_.Pop();
}

int MinStack::GetMin() {
  auto min_elem = minData_.Pop();
  minData_.Push(min_elem);
  return min_elem;
}