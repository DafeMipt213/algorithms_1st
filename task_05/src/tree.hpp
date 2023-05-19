#pragma once

enum class Color { RED, GREEN, BLUE };

struct Object {
  int key;
  Color color;
};

class Tree {
 private:
  const static int t = 2;
  struct Node {
    int keys[2 * t];
    Node *children[2 * t + 1];
    Node *parent;
    int count;
    int countSons;
    bool leaf;
  };
  Node *root = nullptr;
  void insert_to_node(int key, Node *node);
  void sort(Node *node);
  void restruct(Node *node);
  void deletenode(Node *node);
  bool searchKey(int key, Node *node);

 public:
  Tree();
  ~Tree();
  bool Insert(int key);
  void InsertOrUpdate(int key);
  bool Find(int key);
};
