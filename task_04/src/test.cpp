#include <gtest/gtest.h>

#include <iostream>
#include <vector>

#include "order_statistics.hpp"

TEST(OrderStatistics, VerySimple) {
  std::vector<int> data{1};
  ASSERT_EQ(GetOrderStatistics(data, 1), 1);
  data.push_back(3);
  ASSERT_EQ(GetOrderStatistics(data, 2), 3);
  data.push_back(2);
  ASSERT_EQ(GetOrderStatistics(data, 2), 2);
}

TEST(OrderStatistics, Simple) {
  std::vector<int> data{1, 2, 1, 5, 7, 9, 11, 213, 12, 51, 17, 99};
  ASSERT_EQ(GetOrderStatistics(data, 1), 1);
  ASSERT_EQ(GetOrderStatistics(data, 2), 1);
  ASSERT_EQ(GetOrderStatistics(data, 3), 2);
  ASSERT_EQ(GetOrderStatistics(data, 4), 5);
  ASSERT_EQ(GetOrderStatistics(data, 10), 51);
}

TEST(OrderStatistics, LongMassives) {
  std::vector<int> data_1{100, 1,  18, 56,  11, 78, 82, 42, 60, 3,  75, 74, 99,
                          68,  76, 81, 100, 2,  85, 91, 68, 81, 82, 68, 82, 74,
                          55,  41, 25, 96,  44, 64, 80, 80, 43, 64, 22, 26, 7,
                          19,  42, 86, 26,  32, 29, 68, 95, 5,  83, 39};
  ASSERT_EQ(GetOrderStatistics(data_1, 1), 1);
  ASSERT_EQ(GetOrderStatistics(data_1, 2), 2);
  ASSERT_EQ(GetOrderStatistics(data_1, 3), 3);
  ASSERT_EQ(GetOrderStatistics(data_1, 4), 5);
  ASSERT_EQ(GetOrderStatistics(data_1, 50), 100);

  std::vector<int> data_2{38, 39, 54, 27, 59, 79, 56, 25, 42, 2,  69, 56, 100,
                          7,  13, 62, 32, 53, 69, 96, 69, 7,  56, 42, 33, 4,
                          2,  72, 50, 79, 16, 63, 56, 10, 59, 71, 88, 80, 37,
                          27, 70, 59, 86, 6,  83, 28, 40, 25, 33, 89};
  ASSERT_EQ(GetOrderStatistics(data_2, 1), 2);
  ASSERT_EQ(GetOrderStatistics(data_2, 2), 2);
  ASSERT_EQ(GetOrderStatistics(data_2, 3), 4);
  ASSERT_EQ(GetOrderStatistics(data_2, 50), 100);
}