
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Tree tree;
  tree.Insert(5, 10);
  tree.Insert(6, 12);
  tree.Insert(7, 14);
  tree.Insert(11, 22);
  ASSERT_EQ(tree.SearchMin(), 10);
  ASSERT_EQ(tree.root->key, 6);
  ASSERT_EQ(tree.root->right_child->key, 7);
  ASSERT_EQ(tree.root->right_child->right_child->key, 11);
  ASSERT_EQ(tree.root->left_child->key, 5);
  tree.Remove(5);
  ASSERT_EQ(tree.SearchMin(), 12);
}