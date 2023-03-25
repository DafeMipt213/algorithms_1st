#pragma once

class Tree {
 private:
  struct Node {
    Node* parent = nullptr;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    int data;
    int key;
    void operator=(Node other) {
      parent = other.parent;
      left_child = other.left_child;
      right_child = other.right_child;
      data = other.data;
      key = other.key;
    }
  };

 public:
  Node* root = nullptr;
  Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;
  void Remove(int key);
};
