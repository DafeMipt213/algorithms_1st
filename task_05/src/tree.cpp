#include "tree.hpp"

Tree::Tree() {}

Tree::Node* Tree::Balance(Tree::Node* a) {
  if (DiffHeights(a) == -2) {
    Node* b = a->right_child;
    if (DiffHeights(b) == 1) {
      b = RightRotate(b);
    }
    return LeftRotate(a);
  }
  if (DiffHeights(a) == 2) {
    Node* b = a->left_child;
    if (DiffHeights(b) == 1) {
      b = LeftRotate(b);
    }
    return RightRotate(a);
  } else
    return a;
}
void Tree::UpdateHeight(Node* a) {
  if (a->left_child == nullptr && a->right_child == nullptr) {
    a->height = 1;
    return;
  }
  if (a->left_child == nullptr) {
    a->height = a->right_child->height + 1;
    return;
  }
  if (a->right_child == nullptr) {
    a->height = a->left_child->height + 1;
    return;
  }
  a->height = std::min(a->left_child->height, a->right_child->height) + 1;
  return;
}

Tree::Node* Tree::PopMin(Tree::Node* a) {
  if (a->left_child == nullptr) return a->right_child;
  a->left_child = PopMin(a->left_child);
  UpdateHeight(a);
  a = Balance(a);
  return a;
}
Tree::Node* Tree::FindMin(Tree::Node* a) {
  if (a->left_child != nullptr) return FindMin(a->left_child);
  return a;
}

int Tree::DiffHeights(Tree::Node* a) {
  if (a->left_child == nullptr && a->right_child == nullptr) return 0;
  if (a->left_child == nullptr) return -a->right_child->height;
  if (a->right_child == nullptr) return a->left_child->height;
  return a->left_child->height - a->right_child->height;
}
Tree::Node* Tree::LeftRotate(Tree::Node* a) {
  Node* b = a->right_child;
  a->right_child = b->left_child;
  b->left_child = a;
  UpdateHeight(b);
  UpdateHeight(a);
  return b;
}

Tree::Node* Tree::RightRotate(Tree::Node* a) {
  Node* b = a->left_child;
  a->left_child = b->right_child;
  b->right_child = a;
  b->height = std::min(b->left_child->height, b->right_child->height) + 1;
  a->height = std::min(a->left_child->height, a->right_child->height) + 1;
  return b;
}

Tree::Node* Tree::InsertNode(Tree::Node* a, int key, int value) {
  if (a == nullptr) {
    return new Tree::Node(key, value);
  }
  if (key >= a->key) {
    a->right_child = InsertNode(a->right_child, key, value);
  } else {
    a->left_child = InsertNode(a->left_child, key, value);
  }
  UpdateHeight(a);
  a = Balance(a);
  return a;
}

Tree::Node* Tree::EraseNode(Tree::Node* a, int key) {
  if (key > a->key) {
    a->right_child = EraseNode(a->right_child, key);
  }
  if (key < a->key) {
    a->left_child = EraseNode(a->left_child, key);
  } else {
    Tree::Node* l = a->left_child;
    Tree::Node* r = a->right_child;
    delete a;
    if (r == nullptr) return l;
    Tree::Node* min_node = FindMin(r);
    r = PopMin(r);
    min_node->right_child = r;
    min_node->left_child = l;
    return min_node;
  }
  UpdateHeight(a);
  a = Balance(a);
  return a;
}

void Tree::Insert(int key, int value) {
  this->root = InsertNode(this->root, key, value);
}

void Tree::Remove(int key) { this->root = EraseNode(this->root, key); }
int Tree::SearchMin() { return FindMin(this->root)->value; }