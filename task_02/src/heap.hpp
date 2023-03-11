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
  void print();
  

 private:
  std::vector<int> data_;
  void siftUp(int index);
  void siftDown( );
};
