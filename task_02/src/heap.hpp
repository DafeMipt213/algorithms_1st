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
  std::vector<int> data_;
  MinHeap Merge(MinHeap const &heap1);

 private:
  void SiftUp();
  void SiftDown();
};
