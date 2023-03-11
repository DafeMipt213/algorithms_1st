#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::SiftDown() {
  int index = 0;
  int tmp = 0;
  while (true) {
    if (data_.size() <= index * 2 + 1) {
      return;
    } else {
      if (data_.size() == index * 2 + 2) {
        if (data_[index] > data_[index * 2 + 1]) {
          tmp = data_[index * 2 + 1];
          data_[index * 2 + 1] = data_[index];
          data_[index] = tmp;
          index = index * 2 + 1;
        } else {
          return;
        }
      } else {
        int tmp = 0;
        if (data_[index * 2 + 1] > data_[index * 2 + 2]) {
          if (data_[index * 2 + 2] < data_[index]) {
            tmp = data_[index * 2 + 2];
            data_[index * 2 + 2] = data_[index];
            data_[index] = tmp;
            index = index * 2 + 2;
          } else {
            return;
          }
        } else {
          if (data_[index * 2 + 1] < data_[index]) {
            tmp = data_[index * 2 + 1];
            data_[index * 2 + 1] = data_[index];
            data_[index] = tmp;
            index = index * 2 + 1;
          } else {
            return;
          }
        }
      }
    }
  }
}

void MinHeap::SiftUp() {
  int index = data_.size() - 1;
  int tmp = 0;
  while (true) {
    if (index == 0) {
      return;
    } else {
      if (data_[(index - 1) / 2] < data_[index]) {
        return;
      } else {
        tmp = data_[index];
        data_[index] = data_[(index - 1) / 2];
        data_[(index - 1) / 2] = tmp;
        index = (index - 1) / 2;
      }
    }
  }
}

void MinHeap::Push(int n) {
  data_.push_back(n);
  SiftUp();
}

int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  auto result = data_[0];
  data_[0] = data_[data_.size() - 1];
  data_.pop_back();
  SiftDown();
  return result;
}

size_t MinHeap::Size() { return data_.size(); }