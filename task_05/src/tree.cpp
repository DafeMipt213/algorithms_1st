#include "tree.hpp"

#include <exception>
#include <iostream>
Tree::Node* Tree::CreateNode(int key, int value) {
  Node* node = new Node();
  node->key = key;
  node->value = value;
  node->left = node->right = NULL;
  return node;
}

Tree::Node* Tree::Zig(Node* root) {
  Node* new_root = root->left;
  root->left = new_root->right;
  new_root->right = root;
  return new_root;
}

Tree::Node* Tree::Zag(Node* root) {
  Node* new_root = root->right;
  root->right = new_root->left;
  new_root->left = root;
  return new_root;
}

Tree::Node* Tree::Splay(Node* root, int x) {
  if (root == nullptr || root->key == x) return root;

  if (root->key > x) {
    if (root->left == nullptr) return root;
    // Zig-Zig (начало)
    if (root->left->key > x) {
      root->left->left = Splay(root->left->left, x);
      root = Zig(root);
    }
    // Zig-Zag (начало)
    else if (root->left->key < x) {
      root->left->right = Splay(root->left->right, x);
      if (root->left->right != nullptr) root = Zag(root->left->right);
    }
    // Zig
    if (root->left != nullptr) return Zig(root);
    return root;

  } else {
    if (root->right == nullptr) return root;
    // Zag-Zag (начало)
    if (root->right->key < x) {
      root->right->right = Splay(root->right->right, x);
      root = Zag(root);
    }
    // Zag-Zig (начало)
    else if (root->right->key > x) {
      root->right->left = Splay(root->right->left, x);
      if (root->right->left != nullptr) root = Zig(root->right->left);
    }
    // Zag
    if (root->right != nullptr) return Zag(root);
    return root;
  }
}

int Tree::Find(int key) {
  current_root = Splay(current_root, key);
  if (current_root == nullptr || current_root->key != key) return -1;
  return current_root->value;
}

bool Tree::Insert(int key, int value) {
  if (Find(key) != -1) return false;
  if (current_root == nullptr) {
    current_root = CreateNode(key, value);
    return true;
  }
  Node** p_root = &current_root;
  while (*p_root != nullptr) {
    if ((*p_root)->key > key)
      p_root = &(*p_root)->left;
    else
      p_root = &(*p_root)->right;
  }
  *p_root = CreateNode(key, value);
  current_root = Splay(current_root, key);
  return true;
}

void Tree::InsertOrUpdate(int key, int value) {
  if (Find(key) == -1)
    Insert(key, value);
  else
    current_root->value = value;
}

void Tree::Erase(int key) {
  current_root = Splay(current_root, key);
  Node* p_old_node = current_root;
  if (current_root->left == nullptr && current_root->right == nullptr) {
    delete p_old_node;
    return;
  }
  if (current_root->left == nullptr) {
    current_root = current_root->right;
  } else {
    if (current_root->left->right == nullptr) {
      current_root->left->right = current_root->right;
      current_root = current_root->left;
    } else {
      current_root = current_root->left->right;
      current_root->right = current_root->right;
    }
  }
  delete p_old_node;
}