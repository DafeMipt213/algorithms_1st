#pragma once
#include <vector>
struct Node {
  int key{0};
  int height{0};
  Node* left{nullptr};
  Node* right{nullptr};
  Node* insert(Node* p, int k);
  Node* remove(Node* p, int k);
  Node* find(Node* p, int k);
  Node(int n) {
    key = n;
    left = nullptr;
    right = nullptr;
    height = 1;
  }
};

class Tree {
 public:
  Node* root{nullptr};
  Tree(Node* node) { root = node; }
  void insert(int k) { root = root->insert(root, k); }
  void remove(int k) { root = root->remove(root, k); }
  void find(int k) {root = root -> find(root, k);}
  

 private:
  std::vector<int> values{};
};
