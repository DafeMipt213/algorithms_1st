#pragma once

#include <cstddef>
#include <vector>

class MinHeap {
 public:
  void Push(int value);
  int Pop();
  [[nodiscard]] size_t Size() const;
  void swift_Down(size_t i);
  void shift_Up(size_t i);

 private:
  std::vector<int> h;
  size_t HeapSize = 0;
};
