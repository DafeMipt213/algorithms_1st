#pragma once

#include <stack>
#include <vector>

class Stack {
public:
    Stack();
    void Push(int value);
    int Pop();
    int Top();
 private:
  int* data_;
  int size;
  int capacity;
};

class MinStack {
 public:
    MinStack();
    void Push(int value);
    int Pop();
    int GetMin();
    int Top();

 private:
    int* data_;
    int* data_min;
    int min_size;
    int size;
    int min_capacity;
    int capacity;
};