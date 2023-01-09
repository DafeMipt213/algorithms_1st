#pragma once

#include <cstddef>

class MinHeap {
 public:
  void Push(int value);
  int Pop();
  size_t Size();
};
