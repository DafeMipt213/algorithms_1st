
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"


TEST(Tree, Simple) {
  Tree tree;
  tree.Add(1, 1);
  tree.Add(10, 2);
  tree.Add(11, 3);
  tree.Add(100, 4);
  tree.Add(101, 5);
  tree.Add(110, 6);
  tree.Add(111, 7);
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
  tree.Add(1, 1);
  tree.Add(10, 2);
  tree.Add(110, 6);
  tree.Add(111, 7);
  tree.AddOrUpdate(110, 66);  // Update
  tree.AddOrUpdate(11, 3);    // Insert
  tree.AddOrUpdate(10, 22);   // Update
  tree.AddOrUpdate(111, 77);  // Update

  ASSERT_EQ(tree.Find(110), 66);
  ASSERT_EQ(tree.Find(1), 1);
  ASSERT_EQ(tree.Find(10), 22);
  ASSERT_EQ(tree.Find(111), 77);
  ASSERT_EQ(tree.Find(11), 3);
}