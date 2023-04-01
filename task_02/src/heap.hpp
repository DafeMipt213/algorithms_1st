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

  void Sift_up(int index);
  void Sift_down(int index);

 public:
  std::vector<int> array;
};
