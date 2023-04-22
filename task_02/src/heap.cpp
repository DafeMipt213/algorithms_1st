#include "heap.hpp"

#include <cstddef>
#include <stdexcept>

void MinHeap::Push(int n) {
  tree.push_back(n);
  sift_up(Size() - 1);
}

int MinHeap::Pop() {
  if (Size() == 0) throw std::out_of_range("Empty heap");
  int result = tree[0];

  tree[0] = tree[Size() - 1];
  tree.erase(tree.end() - 1);
  sift_down(0);
  return result;
}

size_t MinHeap::Size() { return tree.size(); }

void MinHeap::sift_down(int ind) {
  if (2 * ind + 1 >= Size()) {
    return;
  } else if (2 * ind + 2 >= Size() && tree[2 * ind + 1] < tree[ind]) {
    int tmp = tree[ind];
    tree[ind] = tree[2 * ind + 1];
    tree[2 * ind + 1] = tmp;
  } else {
    if (tree[2 * ind + 1] < tree[2 * ind + 2] &&
        tree[2 * ind + 1] < tree[ind]) {
      int tmp = tree[ind];
      tree[ind] = tree[2 * ind + 1];
      tree[2 * ind + 1] = tmp;
    }
    if (tree[2 * ind + 1] >= tree[2 * ind + 2] &&
        tree[2 * ind + 2] < tree[ind]) {
      int tmp = tree[ind];
      tree[ind] = tree[2 * ind + 2];
      tree[2 * ind + 2] = tmp;
    }
  }
}

void MinHeap::sift_up(int ind) {
  if ((ind - 1) / 2 == 0) {
    if (tree[0] > tree[ind]) {
      int tmp = tree[0];
      tree[0] = tree[ind];
      tree[ind] = tmp;
    }
    return;
  }
  if (tree[ind] < tree[(ind - 1) / 2]) {
    int tmp = tree[ind];
    tree[ind] = tree[(ind - 1) / 2];
    tree[(ind - 1) / 2] = tmp;
  }
}
