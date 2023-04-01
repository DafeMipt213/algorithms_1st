#include "tree.hpp"

#include <iostream>
#include <memory>
#include <stdexcept>

Tree::Tree() {}

bool Tree::Insert(int key, int value) {
  if (!root) {
    root = std::make_unique<Node>();
    return true;
  }
  Node* cur = root.get();
  while (cur) {
    if (key >= cur->key) {
      if (cur->left_child) {
        cur = cur->left_child.get();
      } else {
        cur->left_child = std::make_unique<Node>(key, value);
        cur->left_child->parent = cur;
        return true;
      }
    }
    if (key < cur->key) {
      if (cur->right_chlid) {
        cur = cur->right_chlid.get();
      } else {
        cur->right_chlid = std::make_unique<Node>(key, value);
        cur->right_chlid->parent = cur;
        return true;
      }
    }
  }
}

void Tree::InsertOrUpdate(int key, int value) {}

int Tree::Find(int key) const {
  if (!root) {
    throw std::out_of_range("out of range");
  }
  Node* cur = root.get();
  while (cur) {
    if (key > cur->key) {
      cur = cur->left_child.get();
    }
    if (key < cur->key) {
      cur = cur->right_chlid.get();
    }
    if (key == cur->key) {
      return cur->val;
    }
  }
  throw std::out_of_range("out of range");
}
