#pragma once

class B_Tree {
 private:
  const static int tree_parametr = 2;
  struct Node {
    int keys[2 * tree_parametr];
    Node *children[2 * tree_parametr + 1];
    Node *parent;
    int count;
    int countSons;
    bool leaf;
  };
  Node *root = nullptr;
  void InsertToNode(int key, Node *node);
  void Sort(Node *node);
  void Restruct(Node *node);
  void DeleteNode(Node *node);
  bool SearchKey(int key, Node *node);

 public:
  B_Tree();
  ~B_Tree();
  bool Insert(int key);
  void InsertOrUpdate(int key);
  bool Find(int key);
};