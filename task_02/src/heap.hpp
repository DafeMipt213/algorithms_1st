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
  bool Empty() const;
  void SiftUp(int index);
  void SiftDown(int index);

 private:
  std::vector<int> heap;
};