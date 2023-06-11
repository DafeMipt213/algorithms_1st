#include "iostream"

#pragma once

class Tree {
 public:
  Tree();
  ~Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;
  void PrintAll() const;

 private:
  struct Node {
    int key;
    int value;
    int height;
    Node *left = nullptr;
    Node *right = nullptr;
    Node(int key, int value)
        : key(key), value(value), height(1), left(nullptr), right(nullptr) {}
  };

  Node *node = nullptr;

  int GetHeight(Node *node) const;
  int GetBalanceFactor(Node *node) const;
  void UpdateHeight(Node *node);
  Node *RotateLeft(Node *node);
  Node *RotateRight(Node *node);
  Node *Balance(Node *node);
  Node *InsertNode(Node *node, int key, int value);
  void Clear(Node *node);
};
