#pragma once
#include <iostream>
#include <queue>

template <typename T>
class Node {
 public:
  Node(T key) : key{key}, height{1} {}

  int LeftHeight() const {
    if (left) return left->height;
    return 0;
  }

  int RightHeight() const {
    if (right) return right->height;
    return 0;
  }

  int Difference() const { return RightHeight() - LeftHeight(); }

  void update() { height = std::max(LeftHeight(), RightHeight()) + 1; }

  T key;
  int height;
  Node<T> *left{nullptr};
  Node<T> *right{nullptr};
};

template <typename T>
class AVLTree {
 public:
  AVLTree() = default;

  void Insert(T key) { Insert(root_, key); };
  void Remove(T key) { Remove(root_, key); };

 private:
  Node<T> *root_{nullptr};

  void Insert(Node<T> *node, T key);
  void Remove(Node<T> *node, T key);

  void LeftRotate(Node<T> *node);
  void RightRotate(Node<T> *node);
  void Balance(Node<T> *node);
  void RemoveMinimumNode(Node<T> *node, int key);
};

template <typename T>
void AVLTree<T>::Insert(Node<T> *node, T key) {
  if (!node) {
    node = new Node<T>(key);
    return;
  }

  if (key < node->key)
    Insert(node->left, key);
  else
    Insert(node->right, key);
  Balance(node);
}

template <typename T>
void AVLTree<T>::Remove(Node<T> *node, T key) {
  if (!node) return;

  if (key < node->key) {
    Remove(node->left, key);
  } else if (key > node->key) {
    Remove(node->right, key);
  } else if (!(node->left)) {
    auto right_node = node->right;
    delete node;
    node = right_node;
    return;
  } else if (!(node->right)) {
    auto left_node = node->left;
    delete node;
    node = left_node;
    return;
  } else {
    RemoveMinimumNode(node->right, node->left);
  }
  Balance(node);
}

template <typename T>
void AVLTree<T>::RemoveMinimumNode(Node<T> *node, int key) {
  if (!(node->left)) {
    auto right_node = node->right;
    key = node->key;
    delete node;
    node = right_node;
    return;
  }
  RemoveMinimumNode(node->left, key);
  Balance(node);
}

template <typename T>
void AVLTree<T>::RightRotate(Node<T> *node) {
  auto tmp = node->left;
  node->left = tmp->right;
  tmp->right = node;
  node = tmp;
  tmp->right->update();
  tmp->update();
}

template <typename T>
void AVLTree<T>::LeftRotate(Node<T> *node) {
  auto tmp = node->right;
  node->right = tmp->left;
  tmp->left = node;
  node = tmp;
  tmp->left->update();
  tmp->update();
}

template <typename T>
void AVLTree<T>::Balance(Node<T> *node) {
  node->update();
  if (node->Difference() >= 2) {
    if (node->left->Difference() < 0) RightRotate(node->right);
    LeftRotate(node);
  } else if (node->Difference() < - -2) {
    if (node->left->Difference() > 0) LeftRotate(node->left);
    RightRotate(node);
  }
}