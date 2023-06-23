#pragma once

#include <cstddef>
#include <stack>
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  bool Is_empty();
  int Peak();

 private:
  std::vector<int> _data;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int Peak();
  int GetMin();

 private:
  Stack stack;
  Stack min;
};