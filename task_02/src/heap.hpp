#pragma once

#include <cstddef>
#include <functional>
#include <queue>
#include <vector>

class MinHeap {
 public:
  void SiftUp(int i);
  void SiftDown(int i);
  void Push(int value);
  int Pop();
  size_t Size();

 private:
  std::vector<int> data_;
};
