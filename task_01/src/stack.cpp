#include "stack.hpp"

#include <algorithm>
#include <exception>
#include <iostream>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (data_.empty()) {
    throw std::range_error(
        "can't delete the element of Stack, because it's empty");
  }
  auto result = data_.back();
  data_.pop_back();
  return result;
}
int Stack::Top() { return data_.back(); }

bool Stack::Empty() {
  if (data_.empty()) {
    return true;
  }
  return false;
}

void MinStack::Push(int value) {
  if (!data_.Empty()) {
    data_.Push(value);
    if (min_stack_.Top() >= value) {
      min_stack_.Push(value);
    }
  } else {
    data_.Push(value);
    min_stack_.Push(value);
  }
}

int MinStack::Pop() {
  auto result = data_.Top();
  data_.Pop();
  if (result == min_stack_.Top()) {
    min_stack_.Pop();
  }
  return result;
}
int MinStack::Top() { return data_.Top(); }
int MinStack::GetMin() { return min_stack_.Top(); }