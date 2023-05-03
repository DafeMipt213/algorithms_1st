#include "iostream"
#include "tree.hpp"
#include "queue"

Tree::Tree() {
}

bool Tree::Insert(int key, int value) {
  if (node == nullptr) {
    node = new Node(key, value);
    return true;
  }
  Node* curr = node;
  while (true) {
    if (key == curr->key) {
      return false;
    } else if (key < curr->key) {
      if (curr->left == nullptr) {
        curr->left = new Node(key, value);
        return true;
      } else {
        curr = curr->left;
      }
    } else {
      if (curr->right == nullptr) {
        curr->right = new Node(key, value);
        return true;
      } else {
        curr = curr->right;
      }
    }
  } 
}

void Tree::InsertOrUpdate(int key, int value) {
  if (node == nullptr) {
    node = new Node(key, value);
  } else {
    Node* curr = node;
    while (true) {
      if (key == curr->key) {
        curr->value = value;
        return;
      } else if (key < curr->key) {
        if (curr->left == nullptr) {
          curr->left = new Node(key, value);
          return;
        } else {
          curr = curr->left;
        }
      } else {
        if (curr->right == nullptr) {
          curr->right = new Node(key, value);
          return;
        } else {
          curr = curr->right;
        }
      }
    }
  }
}

int Tree::Find(int key) const {
  Node* curr = node;
  while (curr != nullptr) {
    if (key == curr->key) {
      return curr->value;
    } else if (key < curr->key) {
      curr = curr->left;
    } else {  // key > curr->key
      curr = curr->right;
    }
  }
  return 0;  // key not found
}

void Tree::PrintAll() const {
  if (node == nullptr) {
    printf("Tree is empty");
    return;
  }
  std::queue<Node*> q;
  q.push(node);
  printf("key: value\n");
  while (!q.empty()) {
    Node* curr = q.front();
    q.pop();
    printf("%d: %d\n",curr->key,curr->value);
    if (curr->left != nullptr) {
      q.push(curr->left);
    }
    if (curr->right != nullptr) {
      q.push(curr->right);
    }
  }
} 