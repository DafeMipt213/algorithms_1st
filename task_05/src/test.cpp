
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Tree tree;
  tree.Insert(1, 1);
  tree.Insert(10, 2);
  tree.Insert(11, 3);
  tree.Insert(100, 4);
  tree.Insert(101, 5);
  tree.Insert(110, 6);
  tree.Insert(111, 7);
  ASSERT_EQ(tree.Find(100), 4);
  ASSERT_EQ(tree.Find(101), 5);
  ASSERT_EQ(tree.Find(110), 6);
  ASSERT_EQ(tree.Find(1), 1);
  ASSERT_EQ(tree.Find(10), 2);
  ASSERT_EQ(tree.Find(11), 3);
  ASSERT_EQ(tree.Find(111), 7);
}

TEST(Tree, Simple2) {
  Tree tree;
  tree.Insert(1, 1);
  tree.Insert(10, 2);
  tree.Insert(110, 6);
  tree.Insert(111, 7);
  tree.InsertOrUpdate(110, 66); // Update
  tree.InsertOrUpdate(11, 3);   // Insert
  tree.InsertOrUpdate(10, 22);  // Update
  tree.InsertOrUpdate(111, 77); // Update

  ASSERT_EQ(tree.Find(110), 66);
  ASSERT_EQ(tree.Find(1), 1);
  ASSERT_EQ(tree.Find(10), 22);
  ASSERT_EQ(tree.Find(111), 77);
  ASSERT_EQ(tree.Find(11), 3);
}