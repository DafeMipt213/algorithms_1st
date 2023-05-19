
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

TEST(OrderStatistics, Random) {
  std::vector<int> data{-10, 23, 54, -1, 7, 95, 161, 2143, 2, -100, 17, 99};
  ASSERT_EQ(GetOrderStatistics(data, 1), -10);
  ASSERT_EQ(GetOrderStatistics(data, 2), -1);
  ASSERT_EQ(GetOrderStatistics(data, 3), 2);
  ASSERT_EQ(GetOrderStatistics(data, 4), 7);
  ASSERT_EQ(GetOrderStatistics(data, 11), 2143);
}