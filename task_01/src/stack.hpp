#pragma once
#include <vector>

class Stack {
 public:
  void Push(int value);
  int Pop();
  int GetFirst();

 private:
  std::vector<int> data_ = {};
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();
  int GetFirst();
  

 private:
  std::vector<int> data_ = {};    //stack data
  Stack min_stack_;
};