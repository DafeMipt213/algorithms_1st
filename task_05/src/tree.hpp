#pragma once

class Tree {
    private:
    struct Node {
        Node* parent = nullptr;
        Node* left_child = nullptr;
        Node* right_child = nullptr;
        int key;
        char data;
    };
    public:
    Node* root = nullptr;
    Tree();
    bool Insert(int key, int value);
    void InsertOrUpdate(int key, int value);
    int Find(int key) const;
};