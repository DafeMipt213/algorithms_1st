#pragma once
#include <memory>
#include <utility>

struct Node {
  Node(int key, int value) : key{key}, value{value} {}
  Node(){};
  std::shared_ptr<Node> parent = nullptr;
  std::shared_ptr<Node> left_child = nullptr;
  std::shared_ptr<Node> right_child = nullptr;
  int key = 0;
  int value = 0;
};

class BinTree {
 public:
  BinTree(int key, int val);
  BinTree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

 private:
  std::shared_ptr<Node> root = nullptr;
};

class Treap {
 public:
  Treap(int key, int val);
  void Insert(int key, int val);
  int Remove(int key);
  int Find(int key);

 private:
  std::shared_ptr<Node> Merge(std::shared_ptr<Node> left,
                              std::shared_ptr<Node> right);
  std::pair<std::shared_ptr<Node>, std::shared_ptr<Node>> Split(
      int x, std::shared_ptr<Node> root);
  std::shared_ptr<Node> root = nullptr;
};