#pragma once

#include <stack>
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  int Get();

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();
  int Get();

 private:
  std::vector<int> data_;
  Stack minimum_;
};