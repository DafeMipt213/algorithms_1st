#pragma once
#include <iostream>
#include <array>
#include <vector>
const int MAX_SIZE = 100;

class Stack {
 public:
  void Push(int value);
  int Pop();
  bool isEmpty();
  bool isFull();
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