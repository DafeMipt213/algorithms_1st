
#include <gtest/gtest.h>

#include "sort.hpp"

TEST(SortTest, Simple) { ASSERT_EQ(Sort({}), std::vector<int>{}); }