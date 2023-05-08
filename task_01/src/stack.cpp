#include "stack.hpp"

#include <exception>
#include <iostream>

void Stack::Push(int value) {
  Node* node = new Node();
  node->value = value;
  node->prev = last_;
  last_ = node;
};

int Stack::Pop() {
  int result = last_->value;
  Node* tmp = last_;
  last_ = last_->prev;
  delete tmp;
  return result;
};

void MinStack::Push(int value) {
  Node* node = new Node();
  node->value = value;
  if (last_ == nullptr) {
    node->min = value;
  } else {
    if (value < last_->min) {
      node->min = value;
    } else {
      node->min = last_->min;
    }
  }
  node->prev = last_;
  last_ = node;
}

int MinStack::Pop() {
  if (last_ == nullptr) {
    return 0;
    throw std::range_error("Error");
  }
  int result = last_->value;
  last_ = last_->prev;

  return result;
};

int MinStack::GetMin() {
  if (last_ != nullptr) {
    return last_->min;
  }

  throw std::range_error("Error");
  return 0;
};