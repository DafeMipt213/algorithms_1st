#include "heap.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>

MinHeap::MinHeap() : size(0) {}

int MinHeap::left_child(int i) { return 2 * i + 1; }

int MinHeap::right_child(int i) { return 2 * i + 2; }

int MinHeap::parent(int i) { return (i - 1) / 2; }

void MinHeap::sift_up(int i) {
  while (i > 0 && data_[i] < data_[parent(i)]) {
    std::swap(data_[i], data_[parent(i)]);
    i = parent(i);
  }
}

void MinHeap::sift_down(int i) {
  int min_index = i;
  int l = left_child(i);
  if (l < size && data_[l] < data_[min_index]) {
    min_index = l;
  }
  int r = right_child(i);
  if (l < size && data_[r] < data_[min_index]) {
    min_index = r;
  }
  if (i != min_index) {
    std::swap(data_[i], data_[min_index]);
    sift_down(min_index);
  }
}

void MinHeap::Push(int n) {
  data_.push_back(n);
  size++;
  sift_up(size - 1);
}

int MinHeap::Pop() {
  if (size == 0) {
    throw std::runtime_error("Empty heap error");
  }
  int min_val = data_[0];
  data_[0] = data_[size - 1];
  size--;
  data_.pop_back();
  sift_down(0);
  return min_val;
}

int MinHeap::getLast() {
  if (size == 0) {
    throw std::runtime_error("Empty heap error");
  }
  return data_[size - 1];
}

void MinHeap::Last() {
  if (size == 0) {
    std::cout << "\n The heap is empty";
  } else {
    std::cout << "\n The first element is " << data_[0];
  }
}

int MinHeap::Size() { return size; }