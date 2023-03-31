#include "tree.hpp"

#include <stdexcept>

Tree::Tree() {}

bool Tree::Insert(int key, Color value) {
  return 0;
}  // 1 - получилось, 0 - нет

void Tree::InsertOrUpdate(int key, int value) {}

int Tree::Find(int key) const {
  if (root == nullptr) throw std::out_of_range("Tree is empty");
  return 0;
}
