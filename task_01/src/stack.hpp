#pragma once

#include <stack>
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  bool IsEmpty();

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  Stack data_;
  Stack minData_;
};