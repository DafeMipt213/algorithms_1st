#pragma once
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  int Top();
  bool Empty();

 private:
  std::vector<int> data_ = {};
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();
  int Top();

 private:
  Stack data_;  // stack data
  Stack min_stack_;
};