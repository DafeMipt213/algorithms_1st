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

  void Sift_up(int index);
  void Sift_down(int index);

  int parent_index(int index);
  int left_child_index(int index);
  int right_child_index(int index);
};
