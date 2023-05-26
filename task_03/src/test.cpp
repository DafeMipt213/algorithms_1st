
#include <gtest/gtest.h>

#include "sort.hpp"

TEST(SortTest, Simple) {
  ASSERT_EQ(Sort(std::vector<int>{}, 0 , -1), std::vector<int>{});
  ASSERT_EQ(Sort(std::vector<int>{1}, 0, -1), std::vector<int>{1});
  ASSERT_EQ(Sort(std::vector<int>{1, 2, 3}, 0, 2), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(Sort(std::vector<int>{3, 2, 1}, 0, 2), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(Sort(std::vector<int>{3, 2, -1}, 0, 2), (std::vector<int>{-1, 2, 3}));
  ASSERT_EQ(Sort(std::vector<int>{-1, -2, -5}, 0, 2), (std::vector<int>{-5, -2, -1}));
}

TEST(SortTest, Even) {
  ASSERT_EQ(Sort({1, 1}, 0, 1), (std::vector<int>{1, 1}));
  ASSERT_EQ(Sort({1, 1, 2, 3}, 0, 3), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(Sort({1, 2, 1, 3}, 0, 3), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(Sort({1, 1, 2, 3, 2}, 0, 4), (std::vector<int>{1, 1, 2, 2, 3}));
  ASSERT_EQ(Sort({1, 1, 2, 1, 1, 1, 7}, 0, 6), (std::vector<int>{1, 1, 1, 1, 1, 2, 7}));
  ASSERT_EQ(Sort({1, 4, 3, 2, 1}, 0, 4), (std::vector<int>{1, 1, 2, 3, 4}));
}
