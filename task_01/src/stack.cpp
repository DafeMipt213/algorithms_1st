#include "stack.hpp"
#include <iostream>

void Stack::Push(int value) { 
  Node* n = new Node();
  n-> val = value;
  n-> prev = last;
  last = n;
};

int Stack::Pop() {
  if (last == nullptr){
    return 0;
    std::cout << "Error";
  }
  int result = last->val;
  last  = last->prev;

  return result;
};

void MinStack::Push(int value) { 
        Node* n = new Node();
    n->val = value;
    if (last == nullptr) {
        n->minn = value;
    }
    else {
        if (value < last->minn) {
            n->minn = value;
        }
        else {
            n->minn = last->minn;
        }
    }
    n->prev = last;
    last = n;
}

int MinStack::Pop() {
  if (last == nullptr){
    return 0;
    std::cout << "Error";
  }
  int result = last->val;
  last  = last->prev;

  return result;
};

int MinStack::GetMin() {
  if (last != nullptr)
    return last->minn;
};