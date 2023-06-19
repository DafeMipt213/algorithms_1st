#pragma once
#include <iostream>
#include <vector>

class Tree {
 private:
  struct Node {
    Node() {}
    Node(int key, int value) : key{key}, value{value} {}
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    int height = 1;
    int key;
    int value;
  };
  Node* InsertNode(Node* a, int key, int value);
  Node* EraseNode(Node* a, int key);

  Node* FindMin(Node* a);
  Node* PopMin(Node* a);
  int DiffHeights(Node* a);
  Node* LeftRotate(Node* a);
  Node* RightRotate(Node* a);
  void UpdateHeight(Node* a);
  Node* Balance(Node* a);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

 public:
  Node* root = nullptr;
  void Insert(int key, int value);
  void Remove(int key);
  int SearchMin();
  Tree();
};