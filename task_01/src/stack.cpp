#include "stack.hpp"

void Stack::Push(int value) {
  NodeStack<int>* p = nullptr;
  p = new NodeStack<int>;
  p->item = value;
  p->next = Top;
  Top = p;
}

int Stack::Pop() {
  if (Top == nullptr) {
    return 0;
  }
  NodeStack<int>* p = nullptr;
  int value = Top->item;
  p = Top;
  Top = Top->next;
  delete p;
  return value;
}

void MinStack::Push(int value) {
  minNodeStack<int>* p;
  p = new minNodeStack<int>;
  if (Top == nullptr || Top->nowmin > value) {
    p->nowmin = value;
  } else {
    p->nowmin = Top->nowmin;
  }
  p->item = value;
  p->next = Top;
  Top = p;
}

int MinStack::Pop() {
  if (Top == nullptr) {
    return 0;
  }
  minNodeStack<int>* p;
  int value = Top->item;
  p = Top;
  Top = Top->next;
  delete p;
  return value;
}

int MinStack::GetMin() { return Top->nowmin; }