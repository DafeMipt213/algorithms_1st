
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

TEST(OrderStatistics, Basic) {
  std::vector<int> data{34, -9, 0, 5, 6, 7, -3, -100, 999, 33, 20, 24, 25};
  ASSERT_EQ(GetOrderStatistics(data, 1), -100);
  ASSERT_EQ(GetOrderStatistics(data, 2), -9);
  ASSERT_EQ(GetOrderStatistics(data, 3), -3);
  ASSERT_EQ(GetOrderStatistics(data, 6), 6);
  ASSERT_EQ(GetOrderStatistics(data, 10), 25);
  data.push_back(-999);
  ASSERT_EQ(GetOrderStatistics(data, 1), -999);
  ASSERT_EQ(GetOrderStatistics(data, 2), -100);
  ASSERT_EQ(GetOrderStatistics(data, 3), -9);
  ASSERT_EQ(GetOrderStatistics(data, 4), -3);
  ASSERT_EQ(GetOrderStatistics(data, 7), 6);
  ASSERT_EQ(GetOrderStatistics(data, 11), 25);
}

TEST(OrderStatistics, Exceptions) {
  std::vector<int> data;
  EXPECT_ANY_THROW(GetOrderStatistics(data, 1));
  data = {1, 2, 5, 1, 7, 9, 11, 213, 12, 51, 17, 99};
  EXPECT_ANY_THROW(GetOrderStatistics(data, 100));
}