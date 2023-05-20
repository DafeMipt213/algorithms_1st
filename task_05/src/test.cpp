
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  BinTree tree;
  tree.Insert(4, 5);
  ASSERT_EQ(tree.Find(4), 5);
  tree.Insert(100, 0);
  ASSERT_EQ(tree.Find(100), 0);
}

TEST(Tree, Treap) {
  Treap tree(4, 5);
  tree.Insert(3, 6);
  tree.Insert(10, 7);
  tree.Insert(20, 0);
  ASSERT_EQ(tree.Find(20), 0);
  ASSERT_EQ(tree.Find(4), 5);
  ASSERT_EQ(tree.Find(3), 6);
  ASSERT_EQ(tree.Find(10), 7);

  ASSERT_EQ(tree.Remove(10), 7);
  ASSERT_EQ(tree.Find(20), 0);
  ASSERT_EQ(tree.Find(4), 5);
  ASSERT_EQ(tree.Find(3), 6);

  ASSERT_EQ(tree.Remove(20), 0);
  ASSERT_EQ(tree.Find(4), 5);
  ASSERT_EQ(tree.Find(3), 6);

  ASSERT_EQ(tree.Remove(3), 6);
  ASSERT_EQ(tree.Find(4), 5);
}