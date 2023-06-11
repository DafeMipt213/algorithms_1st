#include "tree.hpp"

#include "iostream"
#include "queue"

Tree::Tree() {}

Tree::~Tree() { Clear(node); }

int Tree::GetHeight(Node *node) const {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

int Tree::GetBalanceFactor(Node *node) const {
  if (node == nullptr) {
    return 0;
  }
  return GetHeight(node->left) - GetHeight(node->right);
}

void Tree::UpdateHeight(Node *node) {
  if (node == nullptr) {
    return;
  }
  node->height = std::max(GetHeight(node->left), GetHeight(node->right)) + 1;
}

Tree::Node *Tree::RotateLeft(Node *node) {
  Node *new_root = node->right;
  node->right = new_root->left;
  new_root->left = node;
  UpdateHeight(node);
  UpdateHeight(new_root);
  return new_root;
}

Tree::Node *Tree::RotateRight(Node *node) {
  Node *new_root = node->left;
  node->left = new_root->right;
  new_root->right = node;
  UpdateHeight(node);
  UpdateHeight(new_root);
  return new_root;
}

Tree::Node *Tree::Balance(Node *node) {
  UpdateHeight(node);
  int balanceFactor = GetBalanceFactor(node);
  if (balanceFactor > 1) {
    if (GetBalanceFactor(node->left) < 0) {
      node->left = RotateLeft(node->left);
    }
    return RotateRight(node);
  }
  if (balanceFactor < -1) {
    if (GetBalanceFactor(node->right) > 0) {
      node->right = RotateRight(node->right);
    }
    return RotateLeft(node);
  }
  return node;
}

Tree::Node *Tree::InsertNode(Node *node, int key, int value) {
  if (node == nullptr) {
    return new Node(key, value);
  }
  if (key == node->key) {
    node->value = value;
    return node;
  }
  if (key < node->key) {
    node->left = InsertNode(node->left, key, value);
  } else {
    node->right = InsertNode(node->right, key, value);
  }
  return Balance(node);
}

bool Tree::Insert(int key, int value) {
  if (Find(key) != 0) {
    return false; // Ключ уже существует в дереве
  }
  node = InsertNode(node, key, value);
  return true;
}

void Tree::InsertOrUpdate(int key, int value) {
  node = InsertNode(node, key, value);
}

int Tree::Find(int key) const {
  Node *curr = node;
  while (curr != nullptr) {
    if (key == curr->key) {
      return curr->value;
    } else if (key < curr->key) {
      curr = curr->left;
    } else {
      curr = curr->right;
    }
  }
  return 0;
}

void Tree::PrintAll() const {
  if (node == nullptr) {
    printf("Tree is empty");
    return;
  }
  std::queue<Node *> q;
  q.push(node);
  printf("key: value\n");
  while (!q.empty()) {
    Node *curr = q.front();
    q.pop();
    printf("%d: %d\n", curr->key, curr->value);
    if (curr->left != nullptr) {
      q.push(curr->left);
    }
    if (curr->right != nullptr) {
      q.push(curr->right);
    }
  }
}

void Tree::Clear(Node *node) {
  if (node == nullptr) {
    return;
  }
  Clear(node->left);
  Clear(node->right);
  delete node;
}