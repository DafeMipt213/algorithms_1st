#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) {
  Tree tree;
}
TEST(Tree, InsertAndFind) {
  Tree tree;

  tree.Insert(10, 100);
  tree.Insert(5, 50);
  tree.Insert(15, 150);

  EXPECT_EQ(tree.Find(10), 100);
  EXPECT_EQ(tree.Find(5), 50);
  EXPECT_EQ(tree.Find(15), 150);
}

TEST(Tree, Update) {
  Tree tree;

  tree.Insert(10, 100);

  tree.InsertOrUpdate(10, 200);

  EXPECT_EQ(tree.Find(10), 200);
}

TEST(Tree, NotFound) {
  Tree tree;

  EXPECT_EQ(tree.Find(20), 0);
}
