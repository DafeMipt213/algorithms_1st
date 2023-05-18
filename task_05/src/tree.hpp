#pragma once
#include <vector>

class Tree {
 private:
  static constexpr int t = 2;
  struct Node{
    Node();
    std::vector<int> keys;
    std::vector<int> values;
    std::vector<Node*> children;
    Node* parent;
    
    int keys_count{0}; // count of keys in Node
    int children_count{0}; // count of children in Node
    bool leaf{true};
  };

  int Find(int key, Node* root) const;
  void NodeDeletion(Node* node); // to delete the Node and all its children
  void SimpleInsert(int key, int value, Node* node); // to insert without reconstruction

  Node* root{nullptr};
 public:
  Tree();
  ~Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;
};
