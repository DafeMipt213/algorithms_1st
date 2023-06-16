
#include <gtest/gtest.h>

#include "sort.hpp"

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
  ASSERT_EQ(Sort({1, 2, 5, 1, 7, 9, 11, 213, 12, 51, 17, 99}),
            (std::vector<int>{1, 1, 2, 5, 7, 9, 11, 12, 17, 51, 99, 213}));
}
