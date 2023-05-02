#pragma once

#include <vector>

class Stack {
 public:
  struct Node {
    int value;
    Node* prev = nullptr;
  };
  void Push(int value);
  int Pop();

 private:
  Node* last = nullptr;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();
  struct Node {
    int value = 0;
    int min = 10e8;
    Node* prev = nullptr;
  };

 private:
  Node* last = nullptr;
};