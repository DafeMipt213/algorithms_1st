
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Tree tree;
  tree.insert(5, 10);
  tree.insert(6, 12);
  tree.insert(7, 14);
  tree.insert(11, 22);
  ASSERT_EQ(tree.root->Key, 6);
  ASSERT_EQ(tree.root->right_child->Key, 7);
  ASSERT_EQ(tree.root->right_child->right_child->Key, 11);
  ASSERT_EQ(tree.root->left_child->Key, 5);
}
