#pragma once
#include <memory>

class Tree {
 public:
  Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

 private:
  struct Node {
    Node(int k, int v) : key{k}, val{v} {}
    Node(){};
    Node* parent = nullptr;
    std::unique_ptr<Node> left_child = nullptr;
    std::unique_ptr<Node> right_chlid = nullptr;
    int key = 0;
    int val = 0;
  } node;
  std::unique_ptr<Node> root = nullptr;
};
