#pragma once
#include <algorithm>
#include <cmath>
#include <cstddef>
#include <stdexcept>

class Tree {
  // AVL-Tree
 public:
  Tree() { root = new Node(); }
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

  bool Balanced() { return abs(root->LeftHeight() - root->RightHeight()) <= 1; }

 private:
  struct Node {
    Node()
        : parent{nullptr},
          left_child{nullptr},
          right_child{nullptr},
          key{nullptr},
          value{nullptr} {}
    Node(const Node *node)
        : parent{node->parent},
          left_child{node->left_child},
          right_child{node->right_child},
          key{new int(*node->key)},
          value{new int(*node->value)} {
      AdoptChildren();
    }
    Node(int key, int value)
        : parent{nullptr},
          left_child{nullptr},
          right_child{nullptr},
          key{new int(key)},
          value{new int(value)} {
      AdoptChildren();
    }

    int *key{nullptr};
    int *value{nullptr};

    Node *parent = nullptr;
    Node *left_child = nullptr;
    Node *right_child = nullptr;

    void ChangeNode(int new_key, int new_value) {
      if (!key)
        key = new int(new_key);
      else
        *key = new_key;
      if (!value)
        value = new int(new_value);
      else
        *value = new_value;
    }

    int Height() {
      if (!left_child && !right_child) return 1;
      if (!left_child) return right_child->Height();
      if (!right_child) return left_child->Height();
      return std::max(left_child->Height(), right_child->Height()) + 1;
    }

    int LeftHeight() {
      if (!left_child)
        return 0;
      else
        return left_child->Height();
    }

    int RightHeight() {
      if (!right_child)
        return 0;
      else
        return right_child->Height();
    }

    void LeftLeftTurn();
    void LeftRightTurn();
    void RightLeftTurn();
    void RightRightTurn();

    void Turn();

    void AdoptChildren() {
      if (left_child) left_child->parent = this;
      if (right_child) right_child->parent = this;
    }

    void Update() {
      this->AdoptChildren();
      if (left_child) left_child->AdoptChildren();
      if (right_child) right_child->AdoptChildren();
    }

  };  // struct Node

  Node *root;
};
