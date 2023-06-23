#pragma once

#include <cstddef>
#include <functional>
#include <queue>
#include <vector>

///
/// class MinHeap {
/// public:
///  void Push(int value);
///  int Pop();
///  size_t Size();
///
/// private:
///  std::priority_queue<int, std::vector<int>, std::greater<int>> data_;
///  void SiftUp(int i);
///  void SiftDown(int i);
///};

class MinHeap {
 public:
  void Push(int value);
  int Pop();
  int Size();

 private:
  std::vector<int> heap;
  void SiftUp();
  void SiftDown();
};
