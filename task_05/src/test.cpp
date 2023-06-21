
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
  tree.InsertOrUpdate(6, 79);
  ASSERT_EQ(tree.Find(6), 79);
  tree.InsertOrUpdate(7, 79);
  ASSERT_EQ(tree.Find(7), 79);
  tree.Remove(6);
}

TEST(Tree, Hard) {
  Tree tree;
  tree.InsertOrUpdate(4, 71);
  tree.InsertOrUpdate(5, 43);
  tree.InsertOrUpdate(6, 2);
  ASSERT_EQ(tree.Find(6), 2);
  ASSERT_EQ(tree.Find(5), 43);
  tree.Remove(5);
  ASSERT_ANY_THROW(tree.Find(5));
}