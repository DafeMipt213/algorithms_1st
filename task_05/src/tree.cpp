#include "tree.hpp"

#include <algorithm>

TreeNode::TreeNode(int nodeKey, int nodeValue)
    : key(nodeKey),
      value(nodeValue),
      left(nullptr),
      right(nullptr),
      height(1) {}

int TreeNode::getKey() const { return key; }

int TreeNode::getValue() const { return value; }

TreeNode *TreeNode::getLeft() const { return left; }

TreeNode *TreeNode::getRight() const { return right; }

void TreeNode::setLeft(TreeNode *newLeft) { left = newLeft; }

void TreeNode::setRight(TreeNode *newRight) { right = newRight; }

void TreeNode::setKey(int newKey) { key = newKey; }

void TreeNode::setValue(int newValue) { value = newValue; }

int TreeNode::getHeight() const { return height; }

void TreeNode::updateHeight() {
  int leftHeight = (left != nullptr) ? left->getHeight() : 0;
  int rightHeight = (right != nullptr) ? right->getHeight() : 0;
  height = 1 + std::max(leftHeight, rightHeight);
}

Tree::Tree() : root(nullptr) {}

bool Tree::Insert(int key, int value) {
  if (root == nullptr) {
    root = new TreeNode(key, value);
    return true;
  } else {
    return Insert(root, key, value) != nullptr;
  }
}

void Tree::InsertOrUpdate(int key, int value) {
  TreeNode *existingNode = FindNode(root, key);
  if (existingNode != nullptr) {
    existingNode->setValue(value);
  } else {
    Insert(key, value);
  }
}

int Tree::Find(int key) const {
  TreeNode *node = FindNode(root, key);
  if (node != nullptr) {
    return node->getValue();
  } else {
    return 0;
  }
}

TreeNode *Tree::Insert(TreeNode *node, int key, int value) {
  if (node == nullptr) {
    return new TreeNode(key, value);
  }

  if (key < node->getKey()) {
    node->setLeft(Insert(node->getLeft(), key, value));
  } else if (key > node->getKey()) {
    node->setRight(Insert(node->getRight(), key, value));
  } else {
    return nullptr;
  }

  node->updateHeight();
  return Balance(node);
}

TreeNode *Tree::FindNode(TreeNode *node, int key) const {
  if (node == nullptr || key == node->getKey()) {
    return node;
  }

  if (key < node->getKey()) {
    return FindNode(node->getLeft(), key);
  } else {
    return FindNode(node->getRight(), key);
  }
}

int Tree::Height(TreeNode *node) const {
  if (node == nullptr) {
    return 0;
  }
  return node->getHeight();
}

int Tree::BalanceFactor(TreeNode *node) const {
  if (node == nullptr) {
    return 0;
  }
  return Height(node->getLeft()) - Height(node->getRight());
}

TreeNode *Tree::RotateLeft(TreeNode *node) {
  TreeNode *pivot = node->getRight();
  node->setRight(pivot->getLeft());
  pivot->setLeft(node);

  node->updateHeight();
  pivot->updateHeight();

  return pivot;
}

TreeNode *Tree::RotateRight(TreeNode *node) {
  TreeNode *pivot = node->getLeft();
  node->setLeft(pivot->getRight());
  pivot->setRight(node);

  node->updateHeight();
  pivot->updateHeight();

  return pivot;
}

TreeNode *Tree::Balance(TreeNode *node) {
  node->updateHeight();

  int balanceFactor = BalanceFactor(node);

  if (balanceFactor > 1) {
    if (BalanceFactor(node->getLeft()) < 0) {
      node->setLeft(RotateLeft(node->getLeft()));
    }
    return RotateRight(node);
  }

  if (balanceFactor < -1) {
    if (BalanceFactor(node->getRight()) > 0) {
      node->setRight(RotateRight(node->getRight()));
    }
    return RotateLeft(node);
  }

  return node;
}
