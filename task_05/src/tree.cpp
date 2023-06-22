#include "tree.hpp"

bool Tree::Insert(int key, int value) {
  if (!root) {
    root = new Node();
    root->ChangeNode(key, value);
    return true;
  }
  Node *r = root;
  while (r) {
    if (!(r->key) || !(r->value)) break;
    if (*r->key == key) return false;
    if (key > *r->key) {
      if (!r->right_child) {
        r->right_child = new Node();
        r->AdoptChildren();
        r = r->right_child;
        break;
      }
      r = r->right_child;
    } else {
      if (!r->left_child) {
        r->left_child = new Node();
        r->AdoptChildren();
        r = r->left_child;
        break;
      }
      r = r->left_child;
    }
  }
  r->ChangeNode(key, value);
  root->Turn();
  return true;
}

void Tree::InsertOrUpdate(int key, int value) {
  if (root == nullptr) {
    root = new Node();
    root->ChangeNode(key, value);
    return;
  }
  Node *r = root;
  while (r) {
    if (!(r->key) || !(r->value)) break;
    if (*r->key == key) {
      r->ChangeNode(key, value);
      break;
    } else if (key > *r->key) {
      if (!r->right_child) {
        r->right_child = new Node();
        r->AdoptChildren();
        r = r->right_child;
        break;
      }
      r = r->right_child;
    } else {
      if (!r->left_child) {
        r->left_child = new Node();
        r->AdoptChildren();
        r = r->left_child;
        break;
      }
      r = r->left_child;
    }
  }
  r->ChangeNode(key, value);
  root->Turn();
}

int Tree::Find(int key) const {
  Node *r = root;
  while (r) {
    if (!(r->key) || !(r->value)) break;
    if (*r->key == key) return *r->value;
    if (key > *r->key) {
      if (!r->right_child) break;
      r = r->right_child;
    } else {
      if (!r->left_child) break;
      r = r->left_child;
    }
  }
  throw std::runtime_error("There is no an element with this key");
}

void Tree::Node::LeftLeftTurn() {
  Node *tmp = this;
  *this = Node(left_child);
  tmp->left_child = right_child;
  right_child = tmp;
  Update();
}

void Tree::Node::LeftRightTurn() {
  Node *tmp_right = this;
  Node *tmp_left = left_child;
  *this = Node(left_child->right_child);
  tmp_right->left_child = right_child;
  tmp_left->right_child = left_child;
  left_child = tmp_left;
  right_child = tmp_right;
  Update();
}

void Tree::Node::RightLeftTurn() {
  Node *tmp_left = this;
  Node *tmp_right = this->right_child;
  *this = Node(right_child->left_child);
  tmp_left->right_child = left_child;
  tmp_right->left_child = right_child;
  left_child = tmp_left;
  right_child = tmp_right;
  Update();
}

void Tree::Node::RightRightTurn() {
  Node *tmp = this;
  *this = Node(right_child);
  tmp->right_child = left_child;
  left_child = tmp;
  Update();
}

void Tree::Node::Turn() {
  int left_H = LeftHeight(), right_H = RightHeight();
  if (abs(left_H - right_H) <= 1) return;
  if (abs(left_H - right_H) > 2)
    (left_H > right_H) ? left_child->Turn() : right_child->Turn();
  (left_H > right_H)
      ? ((left_child->left_child->Height() > left_child->right_child->Height())
             ? LeftLeftTurn()
             : LeftRightTurn())
      : ((right_child->right_child->Height() >
          right_child->right_child->Height())
             ? RightRightTurn()
             : RightLeftTurn());
}