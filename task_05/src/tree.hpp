#pragma once
#include <iostream>
#include <vector>

struct Node {
  Node() {}
  Node(int key, int value) : Key{key}, value{value} {}
  Node* left_child = nullptr;
  Node* right_child = nullptr;
  int height = 1;
  int Key;
  int value;
};

class Tree {
 private:
  Node* InsertNode(Node* a, int key, int value);
  Node* EraseNode(Node* a, int key);

  Node* FindMin(Node* a);
  Node* PopMin(Node* a);
  int DeltaH(Node* a);
  Node* LeftRotate(Node* a);
  Node* RightRotate(Node* a);
  bool UpdateHeight(Node* a);
  Node* Balance(Node* a);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

 public:
  Node* root = nullptr;
  void insert(int key, int value);
  void remove(int key);
  Tree();
};
