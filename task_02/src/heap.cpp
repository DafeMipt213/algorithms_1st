#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

/// void MinHeap::Push(int n) { data_.push(n); }
///
/// int MinHeap::Pop() {
///   if (data_.empty()) throw std::out_of_range("Empty heap");
///   auto result = data_.top();
///   data_.pop();
///   return result;
/// }
///
/// size_t MinHeap::Size() { return data_.size(); }

void MinHeap::Push(int n) {
  heap.push_back(n);
  this->SiftUp();
}

int MinHeap::Pop() {
  if (heap.empty()) throw std::out_of_range("Empty heap");
  auto result = heap[0];
  heap[0] = heap[Size() - 1];
  heap.pop_back();
  SiftDown();
  return result;
}

int MinHeap::Size() { return heap.size(); }

void MinHeap::SiftUp() {
  if (Size() <= 1) {
    return;
  }
  int child = Size() - 1;
  bool is_parent_exist = true;
  while (is_parent_exist && heap[child] < heap[(child - 1) / 2]) {
    int temp = heap[child];
    heap[child] = heap[(child - 1) / 2];
    heap[(child - 1) / 2] = temp;
    if (child == 0) {
      return;
    }
    child = (child - 1) / 2;
  }
}

void MinHeap::SiftDown() {
  int parent = 0;
  if (Size() <= 1) return;
  bool is_right_child_exist = false;
  bool is_left_child_exist = true;
  if (2 * parent + 2 <= Size() - 1) {
    is_right_child_exist = true;
  }

  while (is_left_child_exist && (heap[2 * parent + 1] < heap[parent] ||
                                 heap[2 * parent + 2] < heap[parent])) {
    if (is_right_child_exist) {
      if (heap[2 * parent + 1] < heap[2 * parent + 2]) {
        int temp = heap[parent];
        heap[parent] = heap[2 * parent + 1];
        heap[2 * parent + 1] = temp;
        parent = 2 * parent + 1;
      } else {
        int temp = heap[parent];
        heap[parent] = heap[2 * parent + 2];
        heap[2 * parent + 2] = temp;
        parent = 2 * parent + 2;
      }
      if (2 * parent + 2 <= Size() - 1) {
        is_right_child_exist = true;
        is_left_child_exist = true;
      } else {
        if (2 * parent + 1 <= Size() - 1) {
          is_left_child_exist = true;
          is_right_child_exist = false;
        } else {
          is_left_child_exist = false;
          is_right_child_exist = false;
        }
      }

    } else {
      if (heap[2 * parent + 1] < heap[parent]) {
        int temp = heap[parent];
        heap[parent] = heap[2 * parent + 1];
        heap[2 * parent + 1] = temp;
        parent = 2 * parent + 1;
        is_left_child_exist = false;
        is_right_child_exist = false;
      }
    }
  }
}