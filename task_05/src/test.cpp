
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Node *root = new Node(5);
  Tree *tree = new Tree(root);
  tree->Insert(6);
  tree->Remove(5);
  ASSERT_EQ((tree->root->key), 6);
  tree->Insert(6);
  tree->Insert(6);
  ASSERT_EQ((tree->root->height), 1);
  tree->Insert(9);
  tree->Insert(8);
  ASSERT_EQ((tree->root->key), 8);
  tree->Insert(10);
  ASSERT_EQ((tree->root->key), 8);
}