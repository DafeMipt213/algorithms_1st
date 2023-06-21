
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Tree Btree;
  Btree.Insert(15);
  Btree.Insert(24);
  Btree.Insert(49);
  ASSERT_EQ(Btree.Find(15), 1);
  ASSERT_EQ(Btree.Find(24), 1);
  ASSERT_EQ(Btree.Find(49), 1);
  ASSERT_EQ(Btree.Find(1), 0);
}