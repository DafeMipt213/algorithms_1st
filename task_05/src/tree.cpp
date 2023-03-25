#include "tree.hpp"
#include <stdexcept>

Tree::Tree() {}

bool Tree::Insert(int key, int value) {
  if (root == nullptr) {
    Node* tmpnode = new Node;
    tmpnode->key = key;
    tmpnode->data = value;
    root = tmpnode;
    return true;
  } else {
    Node* tmpnode = new Node;
    tmpnode = root;
    while (true) {
      if (key > tmpnode->key) {
        if (tmpnode->right_child == nullptr) {
          Node* temp = new Node;
          temp->parent = tmpnode;
          temp->left_child = nullptr;
          temp->right_child = nullptr;
          temp->key = key;
          temp->data = value;
          tmpnode->right_child = temp;
          return true;
        } else {
          tmpnode = tmpnode->right_child;
        }
      } else if (key == tmpnode->key) {
        return false;
      } else
      {
        if (root->left_child == nullptr) {
          Node* temp = new Node;
          temp->parent = tmpnode;
          temp->left_child = nullptr;
          temp->right_child = nullptr;
          temp->key = key;
          temp->data = value;
          tmpnode->left_child = temp;
          return true;
        } else {
          tmpnode = tmpnode->left_child;
        }
      }
    }
  }
}

void Tree::InsertOrUpdate(int key, int value) {
  if (root == nullptr) {
    Node* tmpnode = new Node;
    tmpnode->key = key;
    tmpnode->data = value;
    root = tmpnode;
    return;
  } else {
    Node* tmpnode = new Node;
    tmpnode = root;
    while (true) {
      if (key > tmpnode->key) {
        if (tmpnode->right_child == nullptr) {
          Node* temp = new Node;
          temp->parent = tmpnode;
          temp->left_child = nullptr;
          temp->right_child = nullptr;
          temp->key = key;
          temp->data = value;
          tmpnode->right_child = temp;
          return;
        } else {
          tmpnode = tmpnode->right_child;
        }
      } else if (key == tmpnode->key) {
        tmpnode->data = value;
        return;
      } else
      {
        if (root->left_child == nullptr) {
          Node* temp = new Node;
          temp->parent = tmpnode;
          temp->left_child = nullptr;
          temp->right_child = nullptr;
          temp->key = key;
          temp->data = value;
          tmpnode->left_child = temp;
          return;
        } else {
          tmpnode = tmpnode->left_child;
        }
      }
    }
  }
}

int Tree::Find(int key) const {
  if (root == nullptr) {
    throw std::range_error("Tree is empty");
  } else {
    Node* tmpnode = new Node;
    tmpnode->parent = nullptr;
    tmpnode->left_child = root->left_child;
    tmpnode->right_child = root->right_child;
    tmpnode->key = root->key;
    tmpnode->data = root->data;
    while (true) {
      if (key > tmpnode->key) {
        if (root->right_child == nullptr) {
          throw std::range_error("No element with such key in a tree");
        } else {
          tmpnode = tmpnode->right_child;
        }
      } else if (key == tmpnode->key) {
        return tmpnode->data;
      } else {
        if (root->left_child == nullptr) {
          throw std::range_error("Tree is empty");
        } else {
          tmpnode = tmpnode->left_child;
        }
      }
    }
  }
}
