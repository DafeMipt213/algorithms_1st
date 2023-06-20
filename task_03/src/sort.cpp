#include "sort.hpp"

#include <algorithm>
#include <vector>

void Heap::Push(int n) {
  h.push_back(n);
  size_t counter = HeapSize;
  size_t parent = (HeapSize - 1) / 2;
  while (parent >= 0 && counter > 0) {
    if (h[counter] < h[parent]) {
      std::swap(h[counter], h[parent]);
    }
    counter = parent;
    parent = (counter - 1) / 2;
  }
  ++HeapSize;
}

void Heap::Upd_Heap(size_t i) {
  size_t left = 2 * i + 1;
  if (left < HeapSize) {
    if (h[i] > h[left]) {
      std::swap(h[i], h[left]);
      Upd_Heap(left);
    }
  }
  int right = 2 * i + 2;
  if (right < HeapSize) {
    if (h[i] > h[left]) {
      std::swap(h[i], h[right]);
      Upd_Heap(right);
    }
  }
}

int Heap::Pop() {
  if (HeapSize == 0) throw std::out_of_range("Empty heap");
  int result = h[0];
  h[0] = h[HeapSize - 1];
  --HeapSize;
  Upd_Heap(0);
  return result;
}

size_t Heap::Size() const { return HeapSize; }

void Heap::Create(const std::vector<int>& data) {
  for (int i : data) {
    Push(i);
  }
}

std::vector<int> Sort(const std::vector<int>& data) {
  std::vector<int> result;
  Heap h;
  h.Create(data);
  size_t c = h.Size();
  for (int i = 0; i < c; ++i) {
    result.push_back(h.Pop());
  }
  return result;
}