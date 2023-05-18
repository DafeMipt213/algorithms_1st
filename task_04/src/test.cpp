
#include <gtest/gtest.h>

#include <vector>
#include <iostream>

#include "order_statistics.hpp"

// TEST(OrderStatistics, VerySimple){
//   std::vector<int> data{1};
//   ASSERT_EQ(GetOrderStatistics(data, 1), 1);
//   data.push_back(3);
//   ASSERT_EQ(GetOrderStatistics(data, 2), 3);
//   data.push_back(2);
//   ASSERT_EQ(GetOrderStatistics(data, 2), 2);
// }

TEST(OrderStatistics, Simple) {
  std::vector<int> data{1, 2, 1, 5, 7, 9, 11, 213, 12, 51, 17, 99};
  ASSERT_EQ(GetOrderStatistics(data, 1), 1);
  ASSERT_EQ(GetOrderStatistics(data, 2), 1);
  ASSERT_EQ(GetOrderStatistics(data, 3), 2);
  ASSERT_EQ(GetOrderStatistics(data, 4), 5);
  ASSERT_EQ(GetOrderStatistics(data, 10), 51);
}