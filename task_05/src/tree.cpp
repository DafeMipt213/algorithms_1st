#include "tree.hpp"

#include <iostream>

int height(Node* p) {
  if (p) return p->height;
  return 0;
}

void countHeight(Node* p) {
  int left_height = height(p->left);
  int right_height = height(p->right);
  p->height = std::max(left_height, right_height) + 1;
}

int balanceFactor(Node* p) {
  if (p) return height(p->right) - height(p->left);
}

Node* leftRotation(Node* q) {
  Node* p = q->right;
  q->right = p->left;
  p->left = q;
  countHeight(p);
  countHeight(q);
  return p;
}

Node* rightRotation(Node* p) {
  Node* q = p->left;
  p->left = q->right;
  q->right = p;
  countHeight(p);
  countHeight(q);
  return q;
}

Node* balance(Node* p) {
  countHeight(p);
  if (balanceFactor(p) == 2) {
    if (balanceFactor(p->right) < 0) p->right = rightRotation(p->right);
    return leftRotation(p);
  }
  if (balanceFactor(p) == -2) {
    if (balanceFactor(p->left) > 0) p->left = leftRotation(p->left);
    return rightRotation(p);
  }
  return p;
}

Node* Node::insert(Node* p, int k) {
  if (!p) return new Node(k);
  if (k < p->key)
    p->left = insert(p->left, k);
  else if (k > p->key)
    p->right = insert(p->right, k);
  return balance(p);
}

Node* findMin(Node* p) {
  if (p->left == nullptr)
    return p;
  else
    return findMin(p->left);
}

Node* removeMin(Node* p) {
  if (p->left == nullptr) return p->right;
  p->left = removeMin(p->left);
  return balance(p);
}

Node* Node::remove(Node* p, int k) {
  if (!p) return 0;
  if (k < p->key)
    p->left = remove(p->left, k);
  else if (k > p->key)
    p->right = remove(p->right, k);
  else if (k == p->key) {
    Node* q = p->left;
    Node* r = p->right;
    delete p;
    if (!r) return q;
    Node* min = findMin(r);
    min->right = removeMin(r);
    min->left = q;
    return balance(min);
  }
  return balance(p);
}
