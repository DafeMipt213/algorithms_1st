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
  MinHeap operator+(MinHeap const &heap1) {
    MinHeap res;
    res.data_ = data_;
    for (int i = 0; i < heap1.data_.size(); ++i) {
      res.Push(heap1.data_[i]);
    }
    return res;
  }

 private:
  void SiftUp();
  void SiftDown();
};
