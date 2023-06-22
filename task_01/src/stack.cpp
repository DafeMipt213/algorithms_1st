#include <iostream>
#include <stack.hpp>
#include <stdexcept>
#include <vector>

void Stack::Push(int value) { data.push_back(value); }

int Stack::Pop() {
  if (data.empty()) {
    throw std::runtime_error("Stack is empty.");
  }
  int back = data.back();
  data.pop_back();
  return back;
}

void MinStack::Push(int val) {
  data.push_back(val);
  if (data.empty() || val <= data.front()) {
    data.push_back(val);
  }
}

int MinStack::Pop() {
  if (data.empty()) {
    throw std::runtime_error("Stack is empty.");
  }
  int back = data.back();
  data.pop_back();

  if (back == data.front()) {
    data.pop_back();
  }

  return back;
}

int MinStack::GetMin() {
  if (data.empty()) {
    throw std::runtime_error("Stack is empty.");
  }
  return data.front();
}