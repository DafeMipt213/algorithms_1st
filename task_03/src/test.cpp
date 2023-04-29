
#include <gtest/gtest.h>

#include <stdexcept>

#include "sort.hpp"

TEST(MergeSortTest, Simple) {
  ASSERT_EQ(MergeSort({}), std::vector<int>{});
  ASSERT_EQ(MergeSort({1}), std::vector<int>{1});
  ASSERT_EQ(MergeSort({1, 2, 3}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(MergeSort({3, 2, 1}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(MergeSort({3, 2, -1}), (std::vector<int>{-1, 2, 3}));
}

TEST(MergeSortTest, Even) {
  ASSERT_EQ(MergeSort({1, 1}), (std::vector<int>{1, 1}));
  ASSERT_EQ(MergeSort({1, 1, 2, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(MergeSort({1, 2, 1, 3}), (std::vector<int>{1, 1, 2, 3}));
  ASSERT_EQ(MergeSort({1, 1, 2, 3, 2}), (std::vector<int>{1, 1, 2, 2, 3}));
}

TEST(MergeSortTest, Hard) {
  ASSERT_EQ(MergeSort({-3, 5, 9, 10, -20, 504, 1000, -400, 2}),
            (std::vector<int>{-400, -20, -3, 2, 5, 9, 10, 504, 1000}));
  ASSERT_EQ(MergeSort({-1, -2, -3, -4, -5, -6}),
            (std::vector<int>{-6, -5, -4, -3, -2, -1}));
  ASSERT_EQ(MergeSort({1, -1, 1, 2, -2, -2, -3, 3}),
            (std::vector<int>{-3, -2, -2, -1, 1, 1, 2, 3}));
  ASSERT_EQ(MergeSort({-100, -100, -100, -400}),
            (std::vector<int>{-400, -100, -100, -100}));
}