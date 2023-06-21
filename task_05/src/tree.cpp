#include "tree.hpp"
#include <cstddef>
#include <mutex>
#include <iostream>


Tree::Tree() :root(NULL){
    root = nullptr;
}

void Tree::leftRotate(node* x) {
    node* y = x->right;
    x->right = y->left;
    if(y->left != NULL)
        y->left->parent = x;
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
};

void Tree::rightRotate(node *y) {
    node* x = y->left;
    y->left = x->right;
    if(x->right != NULL)
        x->right->parent = y;

    x->parent = y->parent;
    if(y->parent == NULL)
        root = x;
    else {
        if(y == y->parent->right)
            y->parent->right = x;
        else
            y->parent->left = x;
    }
    x->right = y;
    y->parent = x;

}

bool Tree::Insert(int key, int value) { 
    if(Find(key) != -1)
        return false;
    node t = node(0, key, value, NULL, NULL, NULL);
    if( root == nullptr) {
        root = &t;
        t.parent = NULL;
    } else {
        node* p = root;
        node* q = NULL;
        while(p != NULL) {
            q = p;
            if( p->key < t.key)
                p = p->right;
            else
                p = p->left;
        }
        t.parent = q;
        if(q->key < t.key)
            q->right = &t;
        else
            q->left = &t;
    }
    fixInsert(t);


    return true; 
}

void Tree::fixInsert(node t){
    if(&t == root) {
        t.col = 1;
        return;
    }
    node* parent = t.parent;
    while(parent->col == 0) {
        node* grparent = parent->parent;
        if(grparent->left == parent) {
            node* uncle = grparent->right;
            if(uncle != NULL && uncle->col == 0) {
                parent->col = 1;
				uncle->col = 1;
				grparent->col = 0;
				t = *grparent;
				parent = t.parent;
            } else {
                if(parent->right == &t) {
                    leftRotate(parent);
                    std::swap(t, *parent);
                }
                rightRotate(grparent);
                grparent->col = 0;
                parent->col = 1;
                break;
            }  
        } else {
            node* uncle = grparent->left;
            if(uncle != NULL && uncle->col == 0) {
                grparent->col = 0;
                parent->col = 1;
                uncle->col = 1;
                t = *grparent;
                parent = t.parent; 
            } else {
                if(parent->left == &t) {
                    rightRotate(parent);
                    std::swap(*parent, t);
                }
                leftRotate(grparent);
                parent->col = 1;
                grparent->col = 0;
                break; 
            }
        }
    }
    root->col = 1;
}

void Tree::InsertOrUpdate(int key, int value) {
    if(!(Insert(key, value))) {
        search(root, key)->value = value;
        std::cout << value << std::endl;
    }
}

int Tree::Find(int key) const {
    node* t = search(root, key);
    if(t == NULL)
        return -1;
	return t->value;
}

node* Tree::search(node* t, int key) const {
    if(t == NULL or t->key == key)
        return t;
    else
        if(key > t->key)
            return search(t->right, key);
        else
            return search(t->left, key);
}