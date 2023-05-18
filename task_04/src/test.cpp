
#include <gtest/gtest.h>

#include <vector>
#include <iostream>

#include "order_statistics.hpp"

TEST(OrderStatistics, VerySimple){
  std::vector<int> data{1};
  ASSERT_EQ(GetOrderStatistics(data, 1), 1);
}

// TEST(OrderStatistics, Simple) {
//   std::vector<int> data{1, 2, 5, 1, 7, 9, 11, 213, 12, 51, 17, 99};
//   // std::cout << GetOrderStatistics(data, 4);
//   ASSERT_EQ(GetOrderStatistics(data, 1), 1);
//   ASSERT_EQ(GetOrderStatistics(data, 2), 2);
//   ASSERT_EQ(GetOrderStatistics(data, 3), 5);
//   ASSERT_EQ(GetOrderStatistics(data, 4), 7);
//   ASSERT_EQ(GetOrderStatistics(data, 10), 99);
// }