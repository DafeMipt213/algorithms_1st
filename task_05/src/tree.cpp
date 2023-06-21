#include "tree.hpp"

TreeNode::TreeNode(int nodeKey, int nodeValue)
    : key(nodeKey), value(nodeValue), left(nullptr), right(nullptr) {}

int TreeNode::getKey() const { return key; }

int TreeNode::getValue() const { return value; }

TreeNode *TreeNode::getLeft() const { return left; }

TreeNode *TreeNode::getRight() const { return right; }

void TreeNode::setLeft(TreeNode *newLeft) { left = newLeft; }

void TreeNode::setRight(TreeNode *newRight) { right = newRight; }

void TreeNode::setKey(int newKey) { key = newKey; }

void TreeNode::setValue(int newValue) { value = newValue; }

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

  return node;
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