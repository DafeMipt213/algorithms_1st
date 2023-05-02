#include "stack.hpp"

#include <exception>
#include <iostream>

void Stack::Push(int value) {
  Node* node = new Node();
  node->value = value;
  node->prev = last;
  last = node;
};

int Stack::Pop() {
  int result = last->value;
  Node* tmp = last;
  last = last->prev;
  delete tmp;
  return result;
};

void MinStack::Push(int value) {
  Node* node = new Node();
  node->value = value;
  if (last == nullptr) {
    node->min = value;
  } else {
    if (value < last->min) {
      node->min = value;
    } else {
      node->min = last->min;
    }
  }
  node->prev = last;
  last = node;
}

int MinStack::Pop() {
  if (last == nullptr) {
    return 0;
    throw std::range_error("Error");
  }
  int result = last->value;
  last = last->prev;

  return result;
};

int MinStack::GetMin() {
  if (last != nullptr) {
    return last->min;
  }

  throw std::range_error("Error");
  return 0;
};