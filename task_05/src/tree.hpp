#pragma once
#include <vector>
struct Node {
  int key{0};
  int height{0};
  Node *left{nullptr};
  Node *right{nullptr};
  Node *Insert(Node *p, int k);
  Node *Remove(Node *p, int k);
  Node *Find(Node *p, int k);
  Node(int n) {
    key = n;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

class Tree {
 public:
  Node *root{nullptr};
  Tree(Node *node) { root = node; }
  void Insert(int k) { root = root->Insert(root, k); }
  void Remove(int k) { root = root->Remove(root, k); }
  void Find(int k) { root = root->Find(root, k); }

 private:
  std::vector<int> values{};
};
