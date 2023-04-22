
#include <gtest/gtest.h>

#include <stdexcept>

#include "sort.hpp"

TEST(TakePartVectorTest, Simple) {
  EXPECT_THROW(TakeVectorSlice({}, 5, 6), std::out_of_range);
  EXPECT_THROW(TakeVectorSlice({4, 5, 6}, 5, 6), std::out_of_range);
  EXPECT_THROW(TakeVectorSlice({4, 5, 6}, 2, 1), std::out_of_range);
  ASSERT_EQ(TakeVectorSlice({1}, 0, 0), (std::vector<int>{1}));
  ASSERT_EQ(TakeVectorSlice({1, 2, 3}, 0, 1), (std::vector<int>{1, 2}));
  EXPECT_THROW(TakeVectorSlice({3, 2, 1, 4, 7, 6}, 1, 10), std::out_of_range);
  ASSERT_EQ(TakeVectorSlice({3, 2, -1, 5, 6, 7, 9}, 3, 6),
            (std::vector<int>{5, 6, 7, 9}));
}

TEST(MergeTest, Simple) {
  ASSERT_EQ(Merge({}, {}), std::vector<int>{});
  ASSERT_EQ(Merge({1}, {}), std::vector<int>{1});
  ASSERT_EQ(Merge({}, {1, 2, 3}), (std::vector<int>{1, 2, 3}));
  ASSERT_EQ(Merge({1, 3, 5}, {2, 4, 6}), (std::vector<int>{1, 2, 3, 4, 5, 6}));
  ASSERT_EQ(Merge({1, 1, 2, 2, 2}, {1, 2, 3, 4, 5}),
            (std::vector<int>{1, 1, 1, 2, 2, 2, 2, 3, 4, 5}));
}

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