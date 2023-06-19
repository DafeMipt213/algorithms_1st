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

  void SiftUp(size_t index);
  void SiftDown(size_t index);

 private:
  std::vector<int> array;
};
