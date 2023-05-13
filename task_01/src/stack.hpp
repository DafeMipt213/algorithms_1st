#pragma once

#include <vector>

class Stack {
 public:
  ~Stack() { deleteNode(last_); }
  void Push(int value);
  int Pop();

 private:
  struct Node {
    int value;
    Node* prev = nullptr;
  };
  void deleteNode(Node* p) {
    if (p == nullptr) {
      return;
    }
    if (p->prev != nullptr) {
      deleteNode(p->prev);
    }
    delete p;
  }
  Node* last_ = nullptr;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  struct Node {
    int value = 0;
    int min = 10e8;
    Node* prev = nullptr;
  };
  Node* last_ = nullptr;
};