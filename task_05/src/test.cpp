
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Tree tree;
  ASSERT_EQ(tree.Insert(0, 4), true);
  ASSERT_EQ(tree.Insert(1, 10), true);
  ASSERT_EQ(tree.Insert(-6, 9), true);
  ASSERT_EQ(tree.Insert(1, 11), false);
  ASSERT_EQ(tree.Insert(0, -19), false);
  ASSERT_EQ(tree.Find(1), 10);
  ASSERT_EQ(tree.Find(0), 4);
  tree.InsertOrUpdate(0, 9);
  ASSERT_EQ(tree.Find(0), 9);
}

TEST(Tree, Basic) {
  Tree tree;
  ASSERT_EQ(tree.Insert(0, 1), true);
  ASSERT_EQ(tree.Insert(6, 1), true);
  ASSERT_EQ(tree.Insert(-1, 5), true);
  ASSERT_EQ(tree.Insert(6, 7), false);
  ASSERT_EQ(tree.Balanced(), true);
  ASSERT_EQ(tree.Insert(-2, 1), true);
  ASSERT_EQ(tree.Insert(-3, 1), true);
  ASSERT_EQ(tree.Insert(-12, 5), true);
  ASSERT_EQ(tree.Insert(-1, 7), false);
  ASSERT_EQ(tree.Balanced(), true);
  tree.InsertOrUpdate(14, 13);
  tree.InsertOrUpdate(14, 5);
  tree.InsertOrUpdate(100, 6);
  ASSERT_EQ(tree.Balanced(), true);
  tree.InsertOrUpdate(-1, 4);
  tree.InsertOrUpdate(-12, 333);
  tree.InsertOrUpdate(0, 666);
  ASSERT_EQ(tree.Balanced(), true);
  ASSERT_EQ(tree.Find(0), 666);
  ASSERT_EQ(tree.Find(14), 5);
  ASSERT_EQ(tree.Find(100), 6);
  ASSERT_EQ(tree.Find(-1), 4);
  ASSERT_EQ(tree.Find(100), 6);
  ASSERT_EQ(tree.Find(6), 7);
  ASSERT_EQ(tree.Find(-2), 1);
  ASSERT_EQ(tree.Find(-3), 1);
  ASSERT_EQ(tree.Find(-12), 5);
}

TEST(Tree, Exceptions) {
  Tree tree;
  ASSERT_EQ(tree.Insert(0, 4), true);
  ASSERT_EQ(tree.Insert(1, 10), true);
  ASSERT_EQ(tree.Insert(-6, 9), true);
  ASSERT_EQ(tree.Insert(1, 11), false);
  ASSERT_EQ(tree.Insert(0, -19), false);
  EXPECT_ANY_THROW(tree.Find(1000));
}