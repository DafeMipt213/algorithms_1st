#include "tree.hpp"

#include <cstddef>
#include <iostream>
#include <memory>
#include <stdexcept>

BinTree::BinTree(int key, int val) { root = std::make_shared<Node>(key, val); }

BinTree::BinTree(){};

bool BinTree::Insert(int key, int value) {
  if (!root) {
    root = std::make_shared<Node>(key, value);
    return true;
  }
  Node* cur = root.get();
  while (cur) {
    if (key >= cur->key) {
      if (cur->leftChild) {
        cur = cur->leftChild.get();
      } else {
        cur->leftChild = std::make_shared<Node>(key, value);
        cur->leftChild->parent = cur;
        return true;
      }
    } else if (key < cur->key) {
      if (cur->rightChild) {
        cur = cur->rightChild.get();
      } else {
        cur->rightChild = std::make_shared<Node>(key, value);
        cur->rightChild->parent = cur;
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
  Node* cur = root.get();
  while (cur) {
    if (key > cur->key) {
      cur = cur->leftChild.get();
    } else if (key < cur->key) {
      cur = cur->rightChild.get();
    } else if (key == cur->key) {
      return cur->val;
    }
  }
  throw std::out_of_range("out of range");
}

Treap::Treap(int key, int val) { root = std::make_shared<Node>(key, val); }

void Treap::Insert(int key, int val) {
  auto [left, right] = Split(key, root);
  std::shared_ptr<Node> new_node = std::make_shared<Node>(key, val);
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
      cur = cur->rightChild;
    } else if (key < cur->key) {
      cur = cur->leftChild;
    } else if (key == cur->key) {
      return cur->val;
    }
  }
  throw std::out_of_range("out of range");
}

std::shared_ptr<Node> Treap::Merge(std::shared_ptr<Node> left,
                                   std::shared_ptr<Node> right) {
  if (!right) return left;
  if (!left) return right;

  if (left->val > right->val) {
    left->rightChild = Merge(left->rightChild, right);
    return left;
  } else {
    right->leftChild = Merge(left, right->leftChild);
    return right;
  }
}

std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>> Treap::Split(
    int x, std::shared_ptr<Node> root) {
  if (!root) return {nullptr, nullptr};
  if (x > root->key) {
    auto [left, right] = Split(x, root->rightChild);
    root->rightChild = left;
    return {root, right};
  } else {
    auto [left, right] = Split(x, root->leftChild);
    root->leftChild = right;
    return {left, root};
  }
  return {nullptr, nullptr};
}
