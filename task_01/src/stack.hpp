#pragma once

#include <vector>
#include <array>
const int MAX_SIZE = 100; 

class Stack {
 public:
  void Push(int value);
  int Pop();
  bool isEmpty();
  bool isFull();
  
 private:
  std::array<int, MAX_SIZE> data;
  int top = -1;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();
  bool isEmpty();
  bool isFull();

 private:
  std::array<int, MAX_SIZE> data;
  int top = -1;
  int min = 0;
};
