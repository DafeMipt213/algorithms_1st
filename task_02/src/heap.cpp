#include "heap.hpp"

#include <cmath>
#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int n) {
  data_.push_back(n);
  SiftUp();
}

void MinHeap::SiftUp() {
  int n = data_[data_.size() - 1];
  int index = data_.size() - 1;
  int i = index;
  while (i >= 0) {
    i = (index - 1) / 2;
    if (data_[i] > data_[index]) {
      int temp = data_[i];
      data_[i] = data_[index];
      data_[index] = temp;
    } else
      return;
  }
}

int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  int result = data_[0];
  data_[0] = data_[data_.size() - 1];
  data_.pop_back();
  SiftDown();
  return result;
}

void MinHeap::SiftDown()
 {
  if (data_.size() == 0)
    return;
  int index = 0;
  int minimal_index = 0;
  while (2 * index + 1 <= data_.size() - 1)
  {
    if (2 * index + 1 == data_.size() - 1)
    {
      if (data_[index] > data_[2 * index + 1]) 
      {
        int tmp = data_[index];
        data_[index] = data_[2 * index + 1];
        data_[2 * index + 1] = tmp;
      }
      return;
    }
    else
    {
      if (data_[2 * index + 1] < data_[2 * index + 2])
        minimal_index = 2 * index + 1;
      else
        minimal_index = 2 * index + 2;
      if (data_[index] > data_[minimal_index])
      {
        int tmp = data_[index];
        data_[index] = data_[minimal_index];
        data_[minimal_index] = tmp;
        index = minimal_index;
      }
      else
      return;
    }
  }
 }

size_t MinHeap::Size() { return data_.size(); }
