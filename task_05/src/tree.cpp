#include "tree.hpp"

TreeNode::TreeNode(int key, int value) : key(key), value(value), left(nullptr), right(nullptr) {}

Tree::Tree() : root(nullptr) {}

bool Tree::Insert(int key, int value) {
    if (root == nullptr) {
        root = new TreeNode(key, value);
        return true;
    } else {
        return Insert(root, key, value) != nullptr;
    }
}

void Tree::InsertOrUpdate(int key, int value) {
    TreeNode* existingNode = FindNode(root, key);
    if (existingNode != nullptr) {
        existingNode->value = value;
    } else {
        Insert(key, value);
    }
}

int Tree::Find(int key) const {
    TreeNode* node = FindNode(root, key);
    if (node != nullptr) {
        return node->value;
    } else {
        return 0;
    }
}

TreeNode* Tree::Insert(TreeNode* node, int key, int value) {
    if (node == nullptr) {
        return new TreeNode(key, value);
    }

    if (key < node->key) {
        node->left = Insert(node->left, key, value);
    } else if (key > node->key) {
        node->right = Insert(node->right, key, value);
    } else {
        return nullptr; 
    }

    return node;
}

TreeNode* Tree::FindNode(TreeNode* node, int key) const {
    if (node == nullptr || node->key == key) {
        return node;
    }

    if (key < node->key) {
        return FindNode(node->left, key);
    } else {
        return FindNode(node->right, key);
    }
}
