#pragma once

#include <vector>

class Stack {
 public:
  ~Stack() { deleteNode(last_); }
  void Push(int value);
  int Pop();

 protected:
  struct Node {
    int value;
    Node* prev = nullptr;
  };
  void deleteNode(Node* p);
  Node* last_ = nullptr;
};

class MinStack : public Stack {
 public:
  ~MinStack() { deleteNode(last_); }

  void Push(int value);
  int Pop();
  int GetMin();

 protected:
  struct Node {
    int value = 0;
    int min = 10e8;
    Node* prev = nullptr;
  };
  void deleteNode(Node* p);
  Node* last_ = nullptr;
};
