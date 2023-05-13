#include "tree.hpp"

Tree::Tree() {}

Node* Tree::Balance(Node* a) {
  if (DeltaH(a) == -2) {
    Node* b = a->right_child;
    if (DeltaH(b) == 1) {
      b = RightRotate(b);
    }
    return LeftRotate(a);
  }
  if (DeltaH(a) == 2) {
    Node* b = a->left_child;
    if (DeltaH(b) == 1) {
      b = LeftRotate(b);
    }
    return RightRotate(a);
  } else
    return a;
}
bool Tree::UpdateHeight(Node* a) {
  if (a->left_child == nullptr && a->right_child == nullptr) {
    a->height = 1;
    return true;
  }
  if (a->left_child == nullptr) {
    a->height = a->right_child->height + 1;
    return true;
  }
  if (a->right_child == nullptr) {
    a->height = a->left_child->height + 1;
    return true;
  }
  a->height = std::min(a->left_child->height, a->right_child->height) + 1;
  return true;
}

Node* Tree::PopMin(Node* a) {
  if (a->left_child == nullptr) return a->right_child;
  a->left_child = PopMin(a->left_child);
  UpdateHeight(a);
  a = Balance(a);
  return a;
}
Node* Tree::FindMin(Node* a){
  if (a->left_child != nullptr)
    return FindMin(a->left_child);
  return a;
}

int Tree::DeltaH(Node* a) {
  if (a->left_child == nullptr && a->right_child == nullptr) return 0;
  if (a->left_child == nullptr) return -a->right_child->height;
  if (a->right_child == nullptr) return a->left_child->height;
  return a->left_child->height - a->right_child->height;
}
Node* Tree::LeftRotate(Node* a) {
  Node* b = a->right_child;
  a->right_child = b->left_child;
  b->left_child = a;
  UpdateHeight(b);
  UpdateHeight(a);
  // b->height = std::min(b->left_child->height, b->right_child->height) + 1;
  // a->height = std::min(a->left_child->height, a->right_child->height) + 1;
  return b;
}

Node* Tree::RightRotate(Node* a) {
  Node* b = a->left_child;
  a->left_child = b->right_child;
  b->right_child = a;
  b->height = std::min(b->left_child->height, b->right_child->height) + 1;
  a->height = std::min(a->left_child->height, a->right_child->height) + 1;
  return b;
}

Node* Tree::InsertNode(Node* a, int key, int value) {
  if (a == nullptr) {
    return new Node(key, value);
  }
  if (key >= a->Key) {
    a->right_child = InsertNode(a->right_child, key, value);
  } else {
    a->left_child = InsertNode(a->left_child, key, value);
  }
  UpdateHeight(a);
  a = Balance(a);
  return a;
}

Node* Tree::EraseNode(Node* a, int key) {
  if (key > a->Key) {
    a->right_child = EraseNode(a->right_child, key);
  } 
  if (key < a->Key){
    a->left_child = EraseNode(a->left_child, key);
  }
  else{
    Node* l = a->left_child;
    Node* r = a->right_child;
    delete a;
    if (r == nullptr) return l;
    Node* min_node = FindMin(r);
    r = PopMin(r);
    min_node->right_child = r;
    min_node->left_child = l;
    return min_node;
  }
  UpdateHeight(a);
  a = Balance(a);
  return a;
}

void Tree::insert(int key, int value) {
  this->root = InsertNode(this->root, key, value);
}

void Tree::remove(int key) {
  this->root = EraseNode(this->root, key);
}

