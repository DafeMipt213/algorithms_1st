#include "stack.hpp"

#include <algorithm>

Stack::Stack(std::vector<int>&& v) : data_{std::move(v)} {}

Stack::Stack(const std::vector<int>& v) : data_(v) {}

void Stack::Push(int value) { data_.push_back(value); }

int Stack::Pop() {
  if (data_.empty()) throw std::out_of_range("Stack::Pop: empty stack");
  auto result = data_.back();
  data_.pop_back();
  return result;
}

int Stack::GetLast() {
  if (data_.empty()) throw std::out_of_range("Stack::GetLast: empty stack");
  return data_.back();
}

void MinStack::Push(int value) {
  data_.Push(value);
  if (mins_.Empty())
    mins_.Push(value);
  else
    mins_.Push(std::min(value, mins_.GetLast()));
}

int MinStack::Pop() {
  int result = data_.GetLast();
  data_.Pop();
  mins_.Pop();
  return result;
}

int MinStack::GetMin() { return mins_.GetLast(); }