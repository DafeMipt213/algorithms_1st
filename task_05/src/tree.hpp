#pragma once
#include <iostream>
#include <memory>
#include <vector>
class Tree {
 private:
  struct Node {
    Node* parent = nullptr;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    ~Node();
    int data;
    int key;
    bool visited = false;
    void operator=(Node other) {
      parent = other.parent;
      left_child = other.left_child;
      right_child = other.right_child;
      data = other.data;
      key = other.key;
    }
  };

 public:
  void LeftZig(Node*);
  void RightZig(Node*);
  void LeftZigZig(Node*);
  void RightZigZig(Node*);
  void LeftZigZag(Node*);
  void RightZigZag(Node*);
  void Splay(Node*);
  Node* root = nullptr;
  Tree();
  ~Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key);
  void Remove(int key);
  void RemoveSplay(int key);
};