#include "tree.hpp"

#include <exception>
#include <iostream>

std::unique_ptr<Tree::Node> CreateNode(int key, int value) {
  std::unique_ptr<Tree::Node> node = std::make_unique<Tree::Node>();
  node->key = key;
  node->value = value;
  node->left = nullptr;
  node->right = nullptr;
  return node;
}

std::unique_ptr<Tree::Node> Tree::Zig(std::unique_ptr<Tree::Node> root) {
  std::unique_ptr<Tree::Node> new_root = std::move(root->left);
  root->left = std::move(new_root->right);
  new_root->right = std::move(root);
  return new_root;
}

std::unique_ptr<Tree::Node> Tree::Zag(std::unique_ptr<Tree::Node> root) {
  std::unique_ptr<Tree::Node> new_root = std::move(root->right);
  root->right = std::move(new_root->left);
  new_root->left = std::move(root);
  return new_root;
}

std::unique_ptr<Tree::Node> Tree::Splay(std::unique_ptr<Tree::Node> root,
                                        int x) {
  if (root == nullptr || root->key == x) return std::move(root);

  if (root->key > x) {
    if (root->left == nullptr) return std::move(root);
    // Zig-Zig (начало)
    if (root->left->key > x) {
      root->left->left = Splay(std::move(root->left->left), x);
      root = Zig(std::move(root));
    }
    // Zig-Zag (начало)
    else if (root->left->key < x) {
      root->left->right = Splay(std::move(root->left->right), x);
      if (root->left->right != nullptr)
        root = Zag(std::move(root->left->right));
    }
    // Zig
    if (root->left != nullptr) return Zig(std::move(root));
    return std::move(root);

  } else {
    if (root->right == nullptr) return std::move(root);
    // Zag-Zag (начало)
    if (root->right->key < x) {
      root->right->right = Splay(std::move(root->right->right), x);
      root = Zag(std::move(root));
    }
    // Zag-Zig (начало)
    else if (root->right->key > x) {
      root->right->left = Splay(std::move(root->right->left), x);
      if (root->right->left != nullptr)
        root = Zig(std::move(root->right->left));
    }
    // Zag
    if (root->right != nullptr) return Zag(std::move(root));
    return std::move(root);
  }
}

int Tree::Find(int key) {
  current_root = Splay(std::move(current_root), key);
  if (current_root == nullptr || current_root->key != key) return -1;
  return current_root->value;
}

bool Tree::Insert(int key, int value) {
  if (Find(key) != -1) return false;
  if (current_root == nullptr) {
    current_root = CreateNode(key, value);
    return true;
  }
  std::unique_ptr<Node>* p_root = &current_root;
  while (*p_root != nullptr) {
    if ((*p_root)->key > key)
      p_root = &(*p_root)->left;
    else
      p_root = &(*p_root)->right;
  }
  *p_root = CreateNode(key, value);
  current_root = Splay(std::move(current_root), key);
  return true;
}

void Tree::InsertOrUpdate(int key, int value) {
  if (Find(key) == -1)
    Insert(key, value);
  else
    current_root->value = value;
}

void Tree::Erase(int key) {
  current_root = Splay(std::move(current_root), key);
  std::unique_ptr<Node> p_old_node = std::move(current_root);
  if (current_root->left == nullptr && current_root->right == nullptr) {
    return;
  }
  if (current_root->left == nullptr) {
    current_root = std::move(current_root->right);
  } else {
    if (current_root->left->right == nullptr) {
      current_root->left->right = std::move(current_root->right);
      current_root = std::move(current_root->left);
    } else {
      current_root = std::move(current_root->left->right);
      current_root->right = std::move(current_root->right);
    }
  }
}
