#pragma once

#include <stack>
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  int Count();

 private:
  std::vector<int> data_;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();
  int Count();

 private:
  std::vector<int> data_;
  std::vector<int> minData_;
};