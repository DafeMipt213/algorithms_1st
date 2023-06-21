
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) { 
    Tree tree; 
    ASSERT_EQ(tree.Insert(10, 22), bool{true});
    ASSERT_EQ(tree.Insert(11, 25)+tree.Insert(12, 28), bool{true});
    ASSERT_EQ(tree.Find(12), int{28});
    ASSERT_EQ(tree.Find(11), int{25});
    tree.InsertOrUpdate(13, 55);
    tree.InsertOrUpdate(13, 45);
    ASSERT_EQ(tree.Find(13), int{45});
    tree.InsertOrUpdate(10, 34);
    ASSERT_EQ(tree.Find(10), int{34});
}

/*
TEST(SortTest, Simple) {
  ASSERT_EQ(Sort({}), std::vector<int>{});
  ASSERT_EQ(Sort({1}), std::vector<int>{1});
  ASSERT_EQ(Sort({1, 2, 3}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(Sort({3, 2, 1}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(Sort({3, 2, -1}), (std::vector<int>{-1, 2, 3}));
}

TEST(SortTest, Even) {
  ASSERT_EQ(Sort({1, 1}), (std::vector<int>{1, 1}));
  ASSERT_EQ(Sort({1, 1, 2, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(Sort({1, 2, 1, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(Sort({1, 1, 2, 3, 2}), (std::vector<int>{1, 1, 2, 2, 3}));
}
*/