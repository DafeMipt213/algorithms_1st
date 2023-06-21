#include "tree.hpp"
#include "iostream"
#include "queue"

Tree::Tree() {}

Tree::~Tree() { Clear(root); }

int Tree::Height(Node *node) const {
  if (node == nullptr) {
    return 0;
  }
  return node->height;
}

int Tree::BalanceFactor(Node *node) const {
  if (node == nullptr) {
    return 0;
  }
  return Height(node->left) - Height(node->right);
}

void Tree::UpdateHeight(Node *node) {
  if (node == nullptr) {
    return;
  }
  node->height = std::max(Height(node->left), Height(node->right)) + 1;
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
  int balanceFactor = BalanceFactor(node);
  if (balanceFactor > 1) {
    if (BalanceFactor(node->left) < 0) {
      node->left = RotateLeft(node->left);
    }
    return RotateRight(node);
  }
  if (balanceFactor < -1) {
    if (BalanceFactor(node->right) > 0) {
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

bool Tree::Add(int key, int value) {
  if (Find(key) != 0) {
    return false;  // Ключ уже существует в дереве
  }
  root = InsertNode(root, key, value);
  return true;
}

void Tree::AddOrUpdate(int key, int value) {
  root = InsertNode(root, key, value);
}

int Tree::Find(int key) const {
  Node *curr = root;
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
  if (root == nullptr) {
    printf("Tree is empty");
    return;
  }
  std::queue<Node *> q;
  q.push(root);
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
