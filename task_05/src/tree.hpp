#pragma once
#include <iostream>
#include <vector>

struct Node {
  Node(int key, int value);
  Node *left_child_ = nullptr;
  Node *right_child_ = nullptr;
  int key_{};
  int value_{};
  int height_ = 1;
};

Node::Node(int key, int value) {
  key_ = key;
  value_ = value;
}

class AVL_Tree {
 private:
  Node *InsertNode(Node *root, int key, int value);
  Node *RemoveNode(Node *root, int key);
  Node *FindNode(Node *root, int key);

  Node *TurnLeft(Node *root);
  Node *TurnRight(Node *root);
  void NewHeight(Node *root);
  Node *SetBalance(Node *root);
  Node *FindMinRightSubtree(Node *root);
  Node *RemoveMinRightSubtree(Node *root);

  Node *root = nullptr;

 public:
  void Insert(int key, int value);
  void Remove(int key);
  int Find(int key);
};

Node *AVL_Tree::TurnLeft(Node *root) {
  Node *right_subtree = root->right_child_;
  root->right_child_ = right_subtree->left_child_;
  right_subtree->left_child_ = root;
  NewHeight(right_subtree);
  NewHeight(root);
  return right_subtree;
}

Node *AVL_Tree::TurnRight(Node *root) {
  Node *left_subtree = root->left_child_;
  root->left_child_ = left_subtree->right_child_;
  left_subtree->right_child_ = root;
  NewHeight(left_subtree);
  NewHeight(root);
  return left_subtree;
}

Node *AVL_Tree::SetBalance(Node *root) {
  if (root->right_child_ > root->left_child_) {
    Node *right_subtree = root->right_child_;
    if (right_subtree->left_child_ > right_subtree->right_child_)
      right_subtree = TurnRight(right_subtree);

    return TurnLeft(root);
  }
  if (root->right_child_ < root->left_child_) {
    Node *left_subtree = root->left_child_;
    if (left_subtree->left_child_ < left_subtree->right_child_)
      left_subtree = TurnLeft(left_subtree);

    return TurnRight(root);
  }
  return root;
}

void AVL_Tree::NewHeight(Node *root) {
  if (root->left_child_ == nullptr && root->right_child_ == nullptr)
    root->height_ = 1;

  else if (root->left_child_ == nullptr)
    root->height_ = root->right_child_->height_ + 1;

  else if (root->right_child_ == nullptr)
    root->height_ = root->left_child_->height_ + 1;

  else
    root->height_ =
        std::max(root->left_child_->height_, root->right_child_->height_) + 1;
}

Node *AVL_Tree::InsertNode(Node *root, int key, int value) {
  if (root == nullptr) return new Node(key, value);

  if (key >= root->key_)
    root->right_child_ = InsertNode(root->right_child_, key, value);
  else
    root->left_child_ = InsertNode(root->left_child_, key, value);

  NewHeight(root);
  root = SetBalance(root);
  return root;
}

Node *AVL_Tree::FindMinRightSubtree(Node *root) {
  return (root->left_child_ == nullptr)
             ? root
             : FindMinRightSubtree(root->left_child_);
}

Node *AVL_Tree::RemoveMinRightSubtree(Node *root) {
  if (root->left_child_ == nullptr) return root->right_child_;
  root->left_child_ = RemoveMinRightSubtree(root->left_child_);
  NewHeight(root);
  root = SetBalance(root);
  return root;
}

Node *AVL_Tree::RemoveNode(Node *root, int key) {
  if (key > root->key_)
    root->right_child_ = RemoveNode(root->right_child_, key);
  else if (key < root->key_)
    root->left_child_ = RemoveNode(root->left_child_, key);
  else {
    Node *right_subtree = root->right_child_;
    Node *left_subtree = root->left_child_;
    delete root;
    if (right_subtree == nullptr) return left_subtree;
    Node *min_right_subtree = FindMinRightSubtree(right_subtree);
    right_subtree = RemoveMinRightSubtree(right_subtree);
    min_right_subtree->right_child_ = right_subtree;
    min_right_subtree->left_child_ = left_subtree;
    return min_right_subtree;
  }
  NewHeight(root);
  root = SetBalance(root);
  return root;
}

Node *AVL_Tree::FindNode(Node *root, int key) {
  if (root == nullptr) return 0;

  if (key > root->key_)
    return FindNode(root->right_child_, key);
  else if (key < root->key_)
    return FindNode(root->left_child_, key);
  else
    return root;
}

void AVL_Tree::Insert(int key, int value) {
  InsertNode(this->root, key, value);
}

void AVL_Tree::Remove(int key) { RemoveNode(this->root, key); }

int AVL_Tree::Find(int key) { return FindNode(this->root, key)->value_; }