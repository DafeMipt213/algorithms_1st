#pragma once

#include <stack>
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();

 private:
  std::vector<int> data;
};

class MinStack {
 public:
  int Pop();
  int GetMin();
  void Push(int value);

 private:
  int min;
  std::vector<int> data;
};