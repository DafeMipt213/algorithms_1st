#pragma once

#include <algorithm>
#include <cstddef>
#include <vector>

struct Node {
  Node(int k) : key(key), left(nullptr), right(nullptr), height(1), count(1) {}
  int key;
  size_t height;
  size_t count;
  Node* left;
  Node* right;
  int factor();
  void update_height();
  Node* rotate_right();
  Node* rotate_left();
};
class AVL_tree {
  AVL_tree();
  ~AVL_tree();

 public:
  void Insert(int k);
  void Remove(int k);
  int Find(int k) const;

 private:
  void balanced(std::vector<Node**> path);
  void delete_tree();
  Node* root;
  size_t size;
};