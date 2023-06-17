#include "tree.hpp"

//буду писать AVL-дерево

Tree::Tree() {}

bool Tree::Insert(int key, int value) {
  if (!root) {
    root->change_node(key, value);
    return true;
  }
}

void Tree::InsertOrUpdate(int key, int value) {}

int Tree::Find(int key) const { return 0; }
