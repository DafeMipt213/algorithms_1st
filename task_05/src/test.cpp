
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Treap tree;

  ASSERT_EQ(tree.insert(5), true);
  ASSERT_EQ(tree.insert(6), true);
  ASSERT_EQ(tree.insert(5), false);
  ASSERT_EQ(tree.find(5), true);
  ASSERT_EQ(tree.find(7), false);

  tree.erase(5);

  ASSERT_EQ(tree.find(5), false);
}