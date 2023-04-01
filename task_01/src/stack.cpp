#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  auto result = data_.back();
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) { 
  if (data_.size() == 0) {
    data_.push_back(value);
    minimal = value;
  }
  else if (value >= minimal) {
    data_.push_back(value);
  } else {
    data_.push_back(2 * value - minimal);
    minimal = value;
  }
}

int MinStack::Pop() {
  if (data_.size() == 0) {
    return NULL;
  } else if (data_.back() >= minimal) {
    int tmp = data_.back();
    data_.pop_back();
    return tmp;
  } else {
    minimal = 2 * minimal - data_.back();
    int tmp = data_.back();
    data_.pop_back();
    return tmp;
  }
}

int MinStack::GetMin() { return minimal; }