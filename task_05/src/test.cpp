
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Treap tree;

  ASSERT_EQ(tree.Insert(5), true);
  ASSERT_EQ(tree.Insert(6), true);
  ASSERT_EQ(tree.Insert(5), false);
  ASSERT_EQ(tree.Find(5), true);
  ASSERT_EQ(tree.Find(7), false);

  tree.Erase(5);

  ASSERT_EQ(tree.Find(5), false);
}