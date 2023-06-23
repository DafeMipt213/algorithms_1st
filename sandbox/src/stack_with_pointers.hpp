#pragma once

#include <cstddef>
#include <stack>
#include <vector>

struct Node {
  Node(int value);
  ~Node();
  int value;
  Node* previous;
};

class Stack {
 public:
  void Push(int value);
  int Pop();

 private:
  Node* peak = nullptr;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  std::vector<int> data_;
};