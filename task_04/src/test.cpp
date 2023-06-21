
#include <gtest/gtest.h>

#include <vector>

#include "order_statistics.hpp"

TEST(OrderStatistics, Simple) {
  std::vector<int> data{1, 2, 5, 1, 7, 9, 11, 213, 12, 51, 17, 99};
  ASSERT_EQ(GetOrderStatistics(data, 1), 1);
  ASSERT_EQ(GetOrderStatistics(data, 2), 2);
  ASSERT_EQ(GetOrderStatistics(data, 3), 5);
  ASSERT_EQ(GetOrderStatistics(data, 4), 7);
  ASSERT_EQ(GetOrderStatistics(data, 10), 99);
}

TEST(OrderStatistics, EmptyData) {
  std::vector<int> data;
  ASSERT_EQ(GetOrderStatistics(data, 0), -1);
}

TEST(OrderStatistics, SingleElementData) {
  std::vector<int> data{5};
  ASSERT_EQ(GetOrderStatistics(data, 0), 5);
}

TEST(OrderStatistics, LargeData) {
  std::vector<int> data;
  for (int i = 100; i >= 0; i--) {
    data.push_back(i);
  }
  ASSERT_EQ(GetOrderStatistics(data, 0), 0);
  ASSERT_EQ(GetOrderStatistics(data, 50), 50);
  ASSERT_EQ(GetOrderStatistics(data, 100), 100);
}