
#include <gtest/gtest.h>

#include <vector>

#include "order_statistics.hpp"

TEST(OrderStatistics, Simple) {
  std::vector<int> data{1, 2, 5, 1, 7, 9, 11, 213, 12, 55, 17, 99};
  ASSERT_EQ(GetOrderStatistics(data, 1), 1);
  ASSERT_EQ(GetOrderStatistics(data, 2), 2);
  ASSERT_EQ(GetOrderStatistics(data, 3), 5);
  ASSERT_EQ(GetOrderStatistics(data, 4), 7);
  ASSERT_EQ(GetOrderStatistics(data, 10), 99);
}

TEST(OrderStatistics, Custom) {
  std::vector<int> data{-1, -2, 5, 123, 51251, 589, 90, 901923, 3, 123};
  ASSERT_EQ(GetOrderStatistics(data, 0), -2);
  ASSERT_EQ(GetOrderStatistics(data, 1), -1);
  ASSERT_EQ(GetOrderStatistics(data, 2), 3);
  ASSERT_EQ(GetOrderStatistics(data, 3), 5);
  ASSERT_EQ(GetOrderStatistics(data, 4), 90);
  ASSERT_EQ(GetOrderStatistics(data, 6), 123);
}
