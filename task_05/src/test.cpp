
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

 TEST(Tree, Simple) { 
    Node* root = new Node(5);
    Tree* tree = new Tree(root);
    tree -> insert(6);
    
    tree -> remove(5);
    ASSERT_EQ((tree -> root -> key), 6);
    tree -> insert(6);
    tree -> insert(6);
    ASSERT_EQ((tree->root->height), 1);
    tree -> insert(9);
    tree -> insert(8);
    ASSERT_EQ((tree -> root -> key), 8);
    tree -> insert(10);
    ASSERT_EQ((tree -> root -> key), 8);
    
    }