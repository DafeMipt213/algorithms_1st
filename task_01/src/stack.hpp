#pragma once


#include <vector>


class Stack {
 public:
 struct Node{
    int val;
    Node* prev = nullptr;
  };
  void Push(int value);
  int Pop();
  

 private:
  Node* last = nullptr;
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();
  struct Node{
    int val = 0;
    int minn = 10e8;
    Node* prev = nullptr;
  };

 private:
  Node* last = nullptr;
};