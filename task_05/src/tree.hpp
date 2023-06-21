#pragma once

class TreeNode {
 private:
  int key;
  int value;
  TreeNode *left;
  TreeNode *right;

 public:
  TreeNode(int key, int value);
  int getKey() const;
  int getValue() const;
  TreeNode *getLeft() const;
  TreeNode *getRight() const;
  void setKey(int newKey);
  void setValue(int newValue);
  void setLeft(TreeNode *newLeft);
  void setRight(TreeNode *newRight);

  ~TreeNode() {
    delete left;
    delete right;
  }
};

class Tree {
 private:
  TreeNode *root;

 public:
  Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

  ~Tree() { delete root; }

 private:
  TreeNode *Insert(TreeNode *node, int key, int value);
  TreeNode *FindNode(TreeNode *node, int key) const;
};
