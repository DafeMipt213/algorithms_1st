

#include "stack.hpp"

#include <exception>
#include <iostream>

void Stack::Push(int value) {
  Node* node = new Node();
  node->value = value;
  node->prev = last_;
  last_ = node;
};
void Stack::deleteNode(Node* p) {
  if (p == nullptr) {
    return;
  }
  if (p->prev != nullptr) {
    deleteNode(p->prev);
  }
  delete p;
}
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
    node->min = std::min(value, last_->min);
  }
  node->prev = last_;
  last_ = node;
}

int MinStack::Pop() {
  if (last_ == nullptr) {
    throw std::range_error("Error");
  }
  int result = last_->value;
  Node* tmp = last_;
  last_ = last_->prev;
  delete tmp;
  return result;
};
void MinStack::deleteNode(Node* p) {
  if (p == nullptr) {
    return;
  }
  if (p->prev != nullptr) {
    deleteNode(p->prev);
  }
  delete p;
}
int MinStack::GetMin() {
  if (last_ != nullptr) {
    return last_->min;
  }

  throw std::range_error("Error");
  return 0;
};