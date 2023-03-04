
#include <gtest/gtest.h>

#include "sort.hpp"

TEST(SortTest, Simple) {
  ASSERT_EQ(MergeSort({}), std::vector<int>{});
  ASSERT_EQ(MergeSort({1}), std::vector<int>{1});
  ASSERT_EQ(MergeSort({1, 2, 3}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(MergeSort({3, 2, 1}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(MergeSort({3, 2, -1}), (std::vector<int>{-1, 2, 3}));
}

TEST(SortTest, Even) {
  ASSERT_EQ(MergeSort({1, 1}), (std::vector<int>{1, 1}));
  ASSERT_EQ(MergeSort({1, 1, 2, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(MergeSort({1, 2, 1, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(MergeSort({1, 1, 2, 3, 2}), (std::vector<int>{1, 1, 2, 2, 3}));
}
