#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int n) {
  tree.push_back(n);
  SiftUp(Size() - 1);
}

int MinHeap::Pop() {
  if (tree.empty()) throw std::out_of_range("Empty heap");
  int result = tree.front();

  tree[0] = tree.back();
  tree.pop_back();
  SiftDown(0);
  return result;
}

size_t MinHeap::Size() { return tree.size(); }

void MinHeap::SiftDown(int index) {
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  if (left >= Size()) {
    return;
  } else if (right >= Size() && tree[left] < tree[index]) {
    std::swap(tree[index], tree[left]);
  } else {
    if (tree[left] < tree[right] && tree[left] < tree[index]) {
      int tmp = tree[index];
      tree[index] = tree[left];
      tree[left] = tmp;
    }
    if (tree[left] >= tree[right] && tree[right] < tree[index]) {
      int tmp = tree[index];
      tree[index] = tree[right];
      tree[right] = tmp;
    }
  }
}

void MinHeap::SiftUp(int index) {
  int parent = (index - 1) / 2;
  if (parent == 0) {
    if (tree[0] > tree[index]) {
      int tmp = tree[0];
      tree[0] = tree[index];
      tree[index] = tmp;
    }
    return;
  }
  if (tree[index] < tree[parent]) {
    int tmp = tree[index];
    tree[index] = tree[parent];
    tree[parent] = tmp;
  }
}
