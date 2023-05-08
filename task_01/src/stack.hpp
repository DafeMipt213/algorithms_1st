#pragma once

#include <vector>

class Stack {
 public:

  void Push(int value);
  int Pop();

 private:
   struct Node {
    int value;
    Node* prev = nullptr;
  };
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