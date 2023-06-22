#pragma once
#include <stack>
#include <vector>

template <typename T>
struct NodeStack {
  T item;
  NodeStack<T>* next;
};

template <typename T>
struct minNodeStack : NodeStack<T> {
  minNodeStack<T>* next;
  T nowmin;
};
class Stack {
 public:
  void Push(int value);
  int Pop();

 private:
  NodeStack<int>* Top;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  minNodeStack<int>* Top;
};
