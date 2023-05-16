#include "stack.hpp"

#include <algorithm>
#include <stdexcept>

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (data_.empty()) throw std::out_of_range("");

  auto result = data_.back();
  data_.pop_back();
  return result;
}

int Stack::Get() {
  if (data_.empty()) {
    throw std::out_of_range("");
  } else {
    return data_.back();
  }
}

void MinStack::Push(int value) {
  data_.push_back(value);
  try {
    if (minimum_.Get() >= value) minimum_.Push(value);
  } catch (std::out_of_range&) {
    minimum_.Push(value);
  }
}

int MinStack::Pop() {
  if (data_.empty()) throw std::out_of_range("");

  auto result = data_.back();
  data_.pop_back();
  return result;
}

int MinStack::GetMin() {
  auto result = minimum_.Get();
  return result;
}

int MinStack::Get() {
  if (data_.empty()) {
    throw std::out_of_range("");
  } else {
    return data_.back();
  }
}