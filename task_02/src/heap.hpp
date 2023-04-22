#pragma once

#include <cstddef>
#include <functional>
#include <queue>
#include <vector>

class MinHeap {
 public:
  MinHeap();
  MinHeap(std::vector<int> vec);

  void Push(int value);
  int Pop();
  size_t Size();
  int Depth();

  void Print();

 private:
  std::vector<int> data_;

  void SiftUp(size_t index);
  void SiftDown(size_t index);

  size_t GetParentIndex(size_t index);
  size_t GetLeftChildIndex(size_t index);
  size_t GetRightChildIndex(size_t index);
  size_t MinChildIndex(size_t index);
};
