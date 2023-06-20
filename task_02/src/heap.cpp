#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int n) {
  h.push_back(n);
  shift_Up(HeapSize);
  ++HeapSize;
}

void MinHeap::shift_Up(size_t i) {
  while (i > 0 && h[(i - 1) / 2] > h[i]) {
    std::swap(h[(i - 1) / 2], h[i]);
    i = (i - 1) / 2;
  }
}

void MinHeap::swift_Down(size_t i) {
  size_t max_ind = i;
  size_t left = 2 * i + 1;
  if (left <= HeapSize && h[left] < h[max_ind]) {
    max_ind = left;
  }
  size_t right = 2 * i + 2;
  if (right <= HeapSize && h[right] < h[max_ind]) {
    max_ind = right;
  }
  if (i != max_ind) {
    std::swap(h[i], h[max_ind]);
    swift_Down(max_ind);
  }
}

int MinHeap::Pop() {
  if (HeapSize == 0) throw std::out_of_range("Empty heap");
  int result = h[0];
  auto iter_beg = h.cbegin();
  h.erase(iter_beg);
  --HeapSize;
  swift_Down(0);
  return result;
}

size_t MinHeap::Size() const { return HeapSize; }
