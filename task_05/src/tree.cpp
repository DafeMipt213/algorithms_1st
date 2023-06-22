#include "tree.hpp"

#include <iostream>

int Height(Node *p) {
  if (p) return p->height;
  return 0;
}

void CountHeight(Node *p) {
  int left_height = Height(p->left);
  int right_height = Height(p->right);
  p->height = std::max(left_height, right_height) + 1;
}

int BalanceFactor(Node *p) {
  if (p) return Height(p->right) - Height(p->left);
}

Node *LeftRotation(Node *q) {
  Node *p = q->right;
  q->right = p->left;
  p->left = q;
  CountHeight(p);
  CountHeight(q);
  return p;
}

Node *RightRotation(Node *p) {
  Node *q = p->left;
  p->left = q->right;
  q->right = p;
  CountHeight(p);
  CountHeight(q);
  return q;
}

Node *Balance(Node *p) {
  CountHeight(p);
  if (BalanceFactor(p) == 2) {
    if (BalanceFactor(p->right) < 0) p->right = RightRotation(p->right);
    return LeftRotation(p);
  }
  if (BalanceFactor(p) == -2) {
    if (BalanceFactor(p->left) > 0) p->left = LeftRotation(p->left);
    return RightRotation(p);
  }
  return p;
}

Node *Node::Insert(Node *p, int k) {
  if (!p) return new Node(k);
  if (k < p->key)
    p->left = Insert(p->left, k);
  else if (k > p->key)
    p->right = Insert(p->right, k);
  return Balance(p);
}

Node *Node::Find(Node *p, int k) {
  if (p != nullptr) {
    if (key == p->key) {
      return p;
    }
    if (key < p->key)
      p->left = Find(p->left, key);
    else
      p->right = Find(p->right, key);
    return nullptr;
  }
}

Node *FindMin(Node *p) {
  if (p->left == nullptr)
    return p;
  else
    return FindMin(p->left);
}

Node *RemoveMin(Node *p) {
  if (p->left == nullptr) return p->right;
  p->left = RemoveMin(p->left);
  return Balance(p);
}

Node *Node::Remove(Node *p, int k) {
  if (!p) return 0;
  if (k < p->key)
    p->left = Remove(p->left, k);
  else if (k > p->key)
    p->right = Remove(p->right, k);
  else if (k == p->key) {
    Node *q = p->left;
    Node *r = p->right;
    delete p;
    if (!r) return q;
    Node *min = FindMin(r);
    min->right = RemoveMin(r);
    min->left = q;
    return Balance(min);
  }
  return Balance(p);
}
