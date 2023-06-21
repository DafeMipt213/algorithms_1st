
#include <gtest/gtest.h>

#include <vector>

#include "tree.hpp"

TEST(Tree, Simple) { 
    Tree tree; 
    ASSERT_EQ(tree.Insert(15, 22), bool{true});
    ASSERT_EQ(tree.Insert(11, 25), bool{true});
    ASSERT_EQ(tree.Insert(12, 28), bool(true));
    ASSERT_EQ(tree.Find(11), int{25});
    ASSERT_EQ(tree.Find(12), int{28});
    tree.InsertOrUpdate(13, 55);
    tree.InsertOrUpdate(13, 45);
    ASSERT_EQ(tree.Find(13), int{45});
    tree.InsertOrUpdate(15, 34);
    ASSERT_EQ(tree.Find(15), int{34});
}