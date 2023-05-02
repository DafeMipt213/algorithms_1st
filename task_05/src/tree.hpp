#pragma once

class Tree {
 public:
  /*
    Node* root = nullptr;
  */
  Tree();

  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;
};