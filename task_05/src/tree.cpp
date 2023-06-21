#include "tree.hpp"
#include <cstddef>
#include <mutex>
#include <iostream>


Tree::Tree() :root{NULL} {}

void Tree::leftRotate(node* x) {
    if(x->right == NULL)
       return;
    else {
        node* y = x->right;
        if(y->left != NULL) {
            x->right = y->left;
            y->left->parent = x;
        } else
            x->right = NULL;
        if(x->parent != NULL)
            y->parent = x->parent;
        if(x->parent == NULL)
            root = y;
        else {
            if(x == x->parent->left)
               x->parent->left = y;
            else
               x->parent->right = y;
        }
        y->left = x;
        x->parent = y;
     }
};

void Tree::rightRotate(node *x) {
    if(x->left == NULL)
        return;
    else {
        node* y = x->left;
        if(y->right != NULL) {
            x->left = y->right;
            y->right->parent = x;
        } else
            x->left = NULL;
        if(x->parent != NULL)
            y->parent = x->parent;
        if(x->parent == NULL)
           root=y;
        else {
            if(x == x->parent->left)
               x->parent->left = y;
            else
               x->parent->right = y;
        }
        y->right = x;
        x->parent = y;
    }
}

bool Tree::Insert(int key, int value) { 
    if(Find(key) != -1)
        return false;
    node* t = new node(0, key, value, NULL, NULL, NULL);
    node* p = root;
    node* q = NULL;

    if(root == NULL) {
        root = t;
        t->parent = NULL;
    } else {
        while(p != NULL) {
            q = p;
            if(p->key < t->key)
                p = p->right;
            else
                p = p->left;
        }
        t->parent = q;
        if(q->key < t->key)
            q->right = t;
        else
            q->left = t;
    }
    fixInsert(t);
    return true;
}

void Tree::fixInsert(node* t){
    if(t == root) {
        t->col = 1;
        return;
    }
    node* u;
    node* parent = t->parent;
    while(t->parent != NULL and t->parent->col == 0) {
        node* grparent = parent->parent;
        if(grparent->left == t->parent) {
            if(grparent->right != NULL) {
                u = grparent->right;
                if(u->col == 0) {
                    t->parent->col = 1;
                    u->col = 1;
                    grparent->col = 0;
                    t = grparent;
                }
            } else {
                if(t->parent->right == t) {
                    t = t->parent;
                    leftRotate(t);
                }
                t->parent->col = 1;
                grparent->col = 0;
                rightRotate(grparent);
            }
        } else {
            if(grparent->left != NULL) {
                u = grparent->left;
                if(u->col == 0) {
                    t->parent->col = 1;
                    u->col = 1;
                    grparent->col = 0;
                    t = grparent;
                }
            } else {
                if(t->parent->left == t) {
                    t = t->parent;
                    rightRotate(t);
                }
                t->parent->col = 1;
                grparent->col = 0;
                leftRotate(grparent);
            }
        }
        root->col = 1;
    }
}
void Tree::InsertOrUpdate(int key, int value) {
    if(!(Insert(key, value))) {
        search(root, key)->value = value;
        std::cout << value << std::endl;
    }
}

int Tree::Find(int k) const {
    node* t = search(root, k);
    if(t == NULL)
        return -1;
	return t->value;
}

node* Tree::search(node* t, int k) const {
    if(t == NULL or t->key == k)
        return t;
    else
        if(k < t->key)
            return search(t->left, k);
        else
            return search(t->right, k);
}