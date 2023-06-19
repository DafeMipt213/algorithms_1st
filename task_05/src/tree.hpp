#pragma once
#include <memory>
// Splay Дерево
class Tree {
 public:
  Tree(){};

  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  void Erase(int key);
  int Find(int key);

 private:
  struct Node {
    std::unique_ptr<Node> left = nullptr;
    std::unique_ptr<Node> right = nullptr;
    int key;
    int value;
  };
  std::unique_ptr<Node> Zig(std::unique_ptr<Node> x);
  std::unique_ptr<Node> Zag(std::unique_ptr<Node> x);
  std::unique_ptr<Node> Splay(std::unique_ptr<Node> root, int x);

  friend std::unique_ptr<Node> CreateNode(int key, int value);

  std::unique_ptr<Node> current_root;
};
