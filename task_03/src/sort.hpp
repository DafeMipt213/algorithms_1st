#pragma once

#include <iterator>
#include <vector>

class Heap {
 public:
  void Push(int value);
  int Pop();
  [[nodiscard]] size_t Size() const;
  void Upd_Heap(size_t i);
  void Create(const std::vector<int>& data);

 private:
  std::vector<int> h;
  size_t HeapSize = 0;
};

std::vector<int> Sort(const std::vector<int>& data);
