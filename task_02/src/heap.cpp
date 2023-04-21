#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::SiftDown() {
  size_t index = 0;
  int tmp = 0;
  while (true) {
    size_t left_kid = index * 2 + 1;
    size_t right_kid = index * 2 + 2;
    if (data_.size() <= left_kid) {
      return;
    } else {
      if (data_.size() == right_kid) {
        if (data_[index] > data_[left_kid]) {
          tmp = data_[left_kid];
          data_[left_kid] = data_[index];
          data_[index] = tmp;
          index = left_kid;
        } else {
          return;
        }
      } else {
        if (data_[left_kid] > data_[right_kid]) {
          if (data_[right_kid] < data_[index]) {
            std::swap(data_[right_kid], data_[index]);
            index = right_kid;
          } else {
            return;
          }
        } else {
          if (data_[left_kid] < data_[index]) {
            std::swap(data_[left_kid], data_[index]);
            index = left_kid;
          } else {
            return;
          }
        }
      }
    }
  }
}

void MinHeap::SiftUp() {
  size_t index = data_.size() - 1;
  int tmp = 0;
  while (true) {
    if (index == 0) {
      return;
    } else {
      size_t parent = (index - 1) / 2;
      if (data_[parent] < data_[index]) {
        return;
      } else {
        tmp = data_[index];
        data_[index] = data_[parent];
        data_[parent] = tmp;
        index = parent;
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
  data_[0] = data_.back();
  data_.pop_back();
  SiftDown();
  return result;
}

size_t MinHeap::Size() { return data_.size(); }

MinHeap MinHeap::Merge(MinHeap const &heap1) {
  MinHeap res;
  res.data_ = data_;
  for (int i = 0; i < heap1.data_.size(); ++i) {
    res.Push(heap1.data_[i]);
  }
  return res;
}