#pragma once
#include <array>
#include <iostream>
#include <vector>
const int MAX_SIZE = 100;

class Stack {
 public:
  void Push(int value);
  int Pop();
  bool IsEmpty();
  bool IsFull();
  int Top();

 private:
  std::array<int, MAX_SIZE> data;
  int top = -1;
};

class MinStack {
 public:
  void Push(int);
  int Pop();
  int Top();
  int GetMin();

 private:
  Stack stack_;
  Stack min_stack_;
};