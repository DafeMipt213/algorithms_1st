#pragma once

class TreeNode {
 private:
  int key;
  int value;
  int height;
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
  int getHeight() const;
  void updateHeight();

  ~TreeNode() {
    delete left;
    delete right;
  }
};

class Tree {
 private:
  TreeNode *root;
  TreeNode *Insert(TreeNode *node, int key, int value);
  TreeNode *FindNode(TreeNode *node, int key) const;
  TreeNode *RotateLeft(TreeNode *node);
  TreeNode *RotateRight(TreeNode *node);
  TreeNode *Balance(TreeNode *node);
  int Height(TreeNode *node) const;
  int BalanceFactor(TreeNode *node) const;

 public:
  Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

  ~Tree() { delete root; }
};
