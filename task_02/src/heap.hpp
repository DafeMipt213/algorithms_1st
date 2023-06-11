#pragma once

#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <vector>

class MinHeap {
private:
  std::vector<int> heap;
  void SiftUp(int index);
  void SiftDown(int index);

public:
  void Push(int val);
  int Pop();
  bool Empty() const;
  size_t Size() const;
};