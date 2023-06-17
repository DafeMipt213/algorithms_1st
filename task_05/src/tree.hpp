#pragma once

#include <cmath>
#include <cstddef>
#include <stdexcept>

class Tree {
  // AVL-Tree
 public:
  Tree() : root{nullptr} {}
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

  bool Balanced() {
    return abs(root->left_child->Height() - root->right_child->Height()) <= 1;
  }

 private:
  struct Node {
    Node(const Node *node)
        : parent{node->parent},
          left_child{node->left_child},
          right_child{node->right_child},
          key{node->key},
          value{node->value} {
      AdoptChildren();
    }
    Node(int key, int value)
        : parent{nullptr},
          left_child{nullptr},
          right_child{nullptr},
          key{key},
          value{value} {
      AdoptChildren();
    }

    Node *parent = nullptr;
    Node *left_child = nullptr;
    Node *right_child = nullptr;

    int key;
    int value;

    void ChangeNode(int new_key, int new_value) {
      key = new_key;
      value = new_value;
    }

    int Height() {
      if (!parent) return 1;
      return parent->Height() + 1;
    }

    void LeftLeftTurn();
    void LeftRightTurn();
    void RightLeftTurn();
    void RightRightTurn();

    void Turn();

    void AdoptChildren() {
      left_child->parent = this;
      right_child->parent = this;
    }

    void Update() {
      this->AdoptChildren();
      left_child->AdoptChildren();
      right_child->AdoptChildren();
    }

  };  // struct Node

  Node *root = nullptr;
};
