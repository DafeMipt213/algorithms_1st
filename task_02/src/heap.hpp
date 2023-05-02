#pragma once
#include <cstddef>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

class MinHeap {
 public:
  void Push(int value);
  int Pop();
  size_t Size();

 private:
  std::vector<int> tree;
  void SiftDown(int index);
  void SiftUp(int index);
};
