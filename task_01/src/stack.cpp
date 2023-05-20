#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) { 
  data_.push_back( value);
}

int Stack::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty stack");
  int result = data_.back();
  data_.pop_back();
  return result;
}

void MinStack::Push(int value) { 
  if ( data_.empty())
    data_.push_back( value);
  else if ( data_.back() >= value)
    data_.push_back( value);
  data.Push(value);
}

int MinStack::Pop() {
  int result = data.Pop();
  if ( data_.back() == result)
    data_.pop_back();
  return result;
}

int MinStack::GetMin() { return data_.back(); }