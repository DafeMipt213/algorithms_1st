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
    int count_sons;
    bool leaf;
  };
  Node *root = nullptr;
  void InsertToNode(int key, Node *node);
  void Sort(Node *node);
  void Restruct(Node *node);
  void DeleteNode(Node *node);
  bool SearchKey(int key, Node *node);

 public:
  Tree();
  ~Tree();
  void Insert(int key);
  void InsertOrUpdate(int key);
  bool Find(int key);
};
