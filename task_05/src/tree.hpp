#pragma once
struct Node{
  int key;
  Node* parent;
  Node* left;
  Node* right;

  Node(int n, Node* left_child = nullptr, Node* right_child = nullptr)
      :key{n}, left{left_child}, right{right_child} {}
  ~Node()
  {
    delete left;
    delete right;
  }
};

class Tree {
 public:
  Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

private:
  Node* root = nullptr;
  Node* parent = nullptr;
  Node* left_child = nullptr;
  Node* right_child = nullptr;
  Color data;
  int Key;
};
