#pragma once

// Splay Дерево
class Tree {
 public:
  struct Node {
    Node* left = nullptr;
    Node* right = nullptr;
    int key;
    int value;
  };
  Tree(){};

  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  void Erase(int key);
  int Find(int key);

  Node* Zig(Node* x);
  Node* Zag(Node* x);
  Node* Splay(Node* root, int x);
  Node* CreateNode(int key, int value);

 private:
  Node* current_root;
};
