#pragma once

#include <cstddef>
#include <functional>
#include <queue>
#include <vector>

class MinHeap {
 public:
  void Push(int value);
  int Pop();
  size_t Size();
  std::vector<int> heap;

 private:
  void SiftUp(int i);
  void SiftDown(int i);
};
