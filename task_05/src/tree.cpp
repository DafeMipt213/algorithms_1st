#include "tree.hpp"

Tree::Tree() {}

bool Tree::Insert(int key, int value) { 
    if (root == nullptr){
        root -> Key = key;
        return true;
    }
    
    
    return true; 
}

void Tree::InsertOrUpdate(int key, int value) {}

int Tree::Find(int key) const { return 0; }
