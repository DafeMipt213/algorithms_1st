#pragma once

class TreeNode {
public:
    int key;
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int key, int value);
};

class Tree {
private:
    TreeNode* root;

public:
    Tree();
    bool Insert(int key, int value);
    void InsertOrUpdate(int key, int value);
    int Find(int key) const;

private:
    TreeNode* Insert(TreeNode* node, int key, int value);
    TreeNode* FindNode(TreeNode* node, int key) const;
};
