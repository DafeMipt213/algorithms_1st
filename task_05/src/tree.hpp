#pragma once
//red and black tree ||| color  0 - red, 1 - black 

struct node {
    bool col;
    int key;
    int value;
    node* left;
    node* right;
    node* parent;

    node(bool c, int k, int v, node* l, node* r, node* p) :
        col(c), key(k), value(v), left(l), right(r), parent(p) {};
};


class Tree {
  public:
    Tree();
  
    bool Insert(int key, int value);
    void InsertOrUpdate(int key, int value);
    int Find(int key) const;

    void leftRotate(node* x);
    void rightRotate(node* y);
    void fixInsert(node* t);
    node* search(node* t, int key) const;
  protected:
    node * root;
};
