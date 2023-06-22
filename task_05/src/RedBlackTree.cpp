#include "RedBlackTree.hpp"

#include <algorithm>
#include <iostream>

template <typename T>
Red_Black_Tree<T>::Red_Black_Tree() {
  root = nullptr;
}

template <typename T>
Red_Black_Tree<T>::~Red_Black_Tree() {
  delete_tree(root);
}

template <typename T>
void Red_Black_Tree<T>::delete_tree(Node<T>* n) {
  if (n == nullptr) {
    return;
  }
  delete_tree(n->left);
  delete_tree(n->right);
  delete n;
  n = nullptr;
}

template <typename T>
void Red_Black_Tree<T>::left_rotate(Node<T>* n) {
  Node<T>* pivot = n->right;
  pivot->parent = n->parent;
  if (n->parent != nullptr) {
    if (n->parent->left == n) {
      n->parent->left = pivot;
    } else {
      n->parent->right = pivot;
    }
  }
  n->right = pivot->left;
  if (pivot->left != nullptr) {
    pivot->left->parent = n;
  }
  n->parent = pivot;
  pivot->left = n;
}

template <typename T>
void Red_Black_Tree<T>::right_rotate(Node<T>* n) {
  Node<T>* pivot = n->left;
  pivot->parent = n->parent;
  if (n->parent != nullptr) {
    if (n->parent->left == n) {
      n->parent->left = pivot;
    } else {
      n->parent->right = pivot;
    }
  }
  n->left = pivot->right;
  if (pivot->right != nullptr) {
    pivot->right->parent = n;
  }
  n->parent = pivot;
  pivot->right = n;
}

template <typename T>
void Red_Black_Tree<T>::insert(T key) {
  Node<T>* new_node = new Node(key, RED);
  Node<T>* x = root;
  Node<T>* y = root;
  while (x != nullptr) {
    y = x;
    if (new_node->key > x->key) {
      x = x->right;
    } else {
      x = x->left;
    }
  }
  new_node->parent = y;
  if (y != nullptr) {
    if (new_node->key > y->key) {
      y->right = new_node;
    } else {
      y->left = new_node;
    }
  } else {
    root = new_node;
  }
  check_insert(new_node);
}

template <typename T>
void Red_Black_Tree<T>::check_insert(Node<T>* n) {
  Node<T>* parent = n->parent;
  while (n != root && parent->colors == RED) {
    Node<T>* grandparent = parent->parent;
    Node<T>* uncle =
        grandparent->left == parent ? grandparent->right : grandparent->left;
    if (uncle != nullptr && uncle->colors == RED) {
      parent->colors = BLACK;
      uncle->colors = BLACK;
      grandparent->colors = RED;
      n = grandparent;
      parent = n->parent;
    } else if (grandparent->left == parent) {
      if (parent->right == n) {
        left_rotate(parent);
        std::swap(n, parent);
      }
      right_rotate(grandparent);
      grandparent->colors = RED;
      parent->colors = BLACK;
    } else if (grandparent->right == parent) {
      if (parent->left == n) {
        right_rotate(parent);
        std::swap(parent, n);
      }
      left_rotate(grandparent);
      grandparent->colors = RED;
      parent->colors = BLACK;
    }
  }
  root->colors = BLACK;
}

template <typename T>
Node<T>* Red_Black_Tree<T>::find(Node<T>* n, T key) const {
  if (n == nullptr || n->key == key) {
    return n;
  } else if (key > n->key) {
    return find(n->right, key);
  } else {
    return find(n->left, key);
  }
}

template <typename T>
Node<T>* Red_Black_Tree<T>::find(T key) const {
  return find(root, key);
}

template <typename T>
void Red_Black_Tree<T>::remove(T key) {
  Node<T>* del_node = find(root, key);
  if (del_node == nullptr) {
    std::cout << "Key not found" << std::endl;
    return;
  }
  if (del_node->left != nullptr && del_node->right != nullptr) {
    Node<T>* replace = del_node;
    replace = del_node->right;

    while (replace->left != nullptr) {
      replace = replace->left;
    }

    if (del_node->parent != nullptr) {
      if (del_node->parent->left == del_node) {
        del_node->parent->left = replace;
      } else {
        del_node->parent->right = replace;
      }
    } else {
      root = replace;
    }
    Node<T>* child = replace->right;
    Node<T>* parent = replace->parent;
    COLORS color = replace->colors;
    if (parent == del_node) {
      parent = del_node;
    } else {
      if (child != nullptr) {
        child->parent = parent;
      }
      parent->left = child;
      replace->right = del_node->right;
      del_node->right->parent = replace;
    }
    replace->parent = del_node->parent;
    replace->color = del_node->color;
    replace->left = del_node->left;
    del_node->left->parent = replace;
    if (color == BLACK) {
      check_remove(child, parent);
    }
    delete del_node;
    return;
  }
  Node<T>* child = del_node->left != nullptr ? del_node->left : del_node->right;
  Node<T>* parent = del_node->parent;
  COLORS color = del_node->colors;
  if (child) {
    child->parent = parent;
  }
  if (parent) {
    if (del_node == parent->left) {
      parent->left = child;
    } else {
      parent->right = child;
    }
  } else {
    root = child;
  }
  if (color == BLACK) {
    check_remove(child, parent);
  }
  delete del_node;
}

template <typename T>
void Red_Black_Tree<T>::check_remove(Node<T>* node, Node<T>* parent) {
  Node<T>* othernode;
  while ((!node) || node->color == BLACK && node != root) {
    if (parent->left == node) {
      othernode = parent->right;
      if (othernode->color == RED) {
        othernode->color = BLACK;
        parent->color = RED;
        leftRotate(root, parent);
        othernode = parent->right;
      } else {
        if (!(othernode->right) || othernode->right->color == BLACK) {
          othernode->left->color = BLACK;
          othernode->color = RED;
          rightRotate(root, othernode);
          othernode = parent->right;
        }
        othernode->color = parent->color;
        parent->color = BLACK;
        othernode->right->color = BLACK;
        leftRotate(root, parent);
        node = root;
        break;
      }
    } else {
      othernode = parent->left;
      if (othernode->color == RED) {
        othernode->color = BLACK;
        parent->color = RED;
        rightRotate(root, parent);
        othernode = parent->left;
      }
      if ((!othernode->left || othernode->left->color == BLACK) &&
          (!othernode->right || othernode->right->color == BLACK)) {
        othernode->color = RED;
        node = parent;
        parent = node->parent;
      } else {
        if (!(othernode->left) || othernode->left->color == BLACK) {
          othernode->right->color = BLACK;
          othernode->color = RED;
          leftRotate(root, othernode);
          othernode = parent->left;
        }
        othernode->color = parent->color;
        parent->color = BLACK;
        othernode->left->color = BLACK;
        rightRotate(root, parent);
        node = root;
        break;
      }
    }
  }
  if (node) node->color = BLACK;
}