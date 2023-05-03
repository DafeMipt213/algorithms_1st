#include "iostream"

#pragma once


class Tree {
 public:
  Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;
  void PrintAll() const;

 private:
  struct Node {
    
    int key;
    int value;
    Node* left = nullptr;
    Node* right = nullptr;
    Node(int key, int value)
        : key(key), value(value), left(nullptr), right(nullptr) {}
  };

  Node* node = nullptr;
};
