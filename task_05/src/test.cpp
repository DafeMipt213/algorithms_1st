
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Tree tree;
  ASSERT_EQ(tree.Insert(4, 5), true);
  ASSERT_EQ(tree.Insert(6, 6), true);
  ASSERT_EQ(tree.Insert(4, 6), false);
  ASSERT_EQ(tree.Find(4), 5);
  tree.Remove(4);
  tree.InsertOrUpdate(6, 78);
  ASSERT_EQ(tree.Find(6), 78);
}