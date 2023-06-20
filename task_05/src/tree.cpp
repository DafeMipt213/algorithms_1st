#include "tree.hpp"

#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

BinTree::BinTree(int key, int value) {
  root = std::make_shared<Node>(key, value);
}

BinTree::BinTree(){};

bool BinTree::Insert(int key, int value) {
  if (!root) {
    root = std::make_shared<Node>(key, value);
    return true;
  }
  std::shared_ptr<Node> cur = root;
  while (cur) {
    if (key >= cur->key) {
      if (cur->right_child) {
        cur = cur->right_child;
      } else {
        cur->right_child = std::make_shared<Node>(key, value);
        cur->right_child->parent = cur;
        return true;
      }
    } else if (key < cur->key) {
      if (cur->left_child) {
        cur = cur->left_child;
      } else {
        cur->left_child = std::make_shared<Node>(key, value);
        cur->left_child->parent = cur;
        return true;
      }
    }
  }
  return false;
}

void BinTree::InsertOrUpdate(int key, int value) {}

int BinTree::Find(int key) const {
  if (!root) {
    throw std::out_of_range("out of range");
  }
  std::shared_ptr<Node> cur = root;
  while (cur) {
    if (key > cur->key) {
      cur = cur->right_child;
    } else if (key < cur->key) {
      cur = cur->left_child;
    } else if (key == cur->key) {
      return cur->priority;
    }
  }
  throw std::out_of_range("out of range");
}

//-------------//-------------//

Treap::Treap(int key, int priority) {
  root = std::make_shared<Node>(key, priority);
}

void Treap::Insert(int key, int priority) {
  auto [left, right] = Split(key, root);
  std::shared_ptr<Node> new_node = std::make_shared<Node>(key, priority);
  std::shared_ptr<Node> new_left = Merge(left, new_node);
  root = Merge(new_left, right);
}

int Treap::Remove(int key) {
  int saved = Find(key);
  auto [left, right1] = Split(key - 1, root);
  auto [unnecessary, right2] = Split(key, right1);
  Merge(left, right2);
  return saved;
}

int Treap::Find(int key) {
  if (!root) {
    throw std::out_of_range("out of range");
  }
  std::shared_ptr<Node> cur = root;
  while (cur) {
    if (key > cur->key) {
      cur = cur->right_child;
    } else if (key < cur->key) {
      cur = cur->left_child;
    } else if (key == cur->key) {
      return cur->priority;
    }
  }
  throw std::out_of_range("out of range");
}

std::shared_ptr<Node> Treap::Merge(std::shared_ptr<Node> left,
                                   std::shared_ptr<Node> right) {
  if (!right) return left;
  if (!left) return right;

  if (left->priority > right->priority) {
    left->right_child = Merge(left->right_child, right);
    return left;
  } else {
    right->left_child = Merge(left, right->left_child);
    return right;
  }
}

std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>> Treap::Split(
    int x, std::shared_ptr<Node> root) {
  if (!root) return {nullptr, nullptr};
  if (x > root->key) {
    auto [left, right] = Split(x, root->right_child);
    root->right_child = left;
    return {root, right};
  } else {
    auto [left, right] = Split(x, root->left_child);
    root->left_child = right;
    return {left, root};
  }
  return {nullptr, nullptr};
}
