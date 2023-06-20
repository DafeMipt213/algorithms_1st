
#include <gtest/gtest.h>

#include <vector>

#include "order_statistics.hpp"

TEST(OrderStatistics, Simple) {
  std::vector<int> data{
      1,  2,   5,  1,  7,  9,
      11, 213, 12, 51, 17, 99};  //{1 1 2 5 7 9 11 12 17 51 99 213}
  ASSERT_EQ(GetOrderStatistics(data, 0), 1);
  ASSERT_EQ(GetOrderStatistics(data, 2), 2);
  ASSERT_EQ(GetOrderStatistics(data, 3), 5);
  ASSERT_EQ(GetOrderStatistics(data, 4), 7);
  ASSERT_EQ(GetOrderStatistics(data, 10), 99);

  std::vector<int> data2{23, -1, 5};
  ASSERT_EQ(GetOrderStatistics(data2, 0), -1);
  ASSERT_EQ(GetOrderStatistics(data2, 1), 5);

  std::vector<int> data3{1};
  ASSERT_EQ(GetOrderStatistics(data3, 0), 1);

  std::vector<int> data4{4, 3, 2, 1};
  ASSERT_EQ(GetOrderStatistics(data4, 3), 4);
  ASSERT_EQ(GetOrderStatistics(data4, 2), 3);
  ASSERT_EQ(GetOrderStatistics(data4, 1), 2);
  ASSERT_EQ(GetOrderStatistics(data4, 0), 1);
}