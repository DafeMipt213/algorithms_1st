
#include <gtest/gtest.h>

#include <stack>

#include "utils.hpp"

TEST(TestGetNumbersOfSum, Simple) {
  ASSERT_EQ(GetNumbersOfSum({-10, -2, 0, 3, 6, 7, 11, 14}, 3),
            std::make_pair(2ul, 3ul));
  ASSERT_EQ(GetNumbersOfSum({-10, -2, 0, 3, 6, 7, 11, 13}, 3),
            std::make_pair(0ul, 7ul));
}

TEST(TestGetNumbersOfSum, Exceptions) {
  std::vector<int> data = {};
  ASSERT_ANY_THROW(GetNumbersOfSum(data, 0));
  EXPECT_THROW(GetNumbersOfSum({1}, 1), std::out_of_range);
  EXPECT_THROW(GetNumbersOfSum({1, 2, 1}, 10), std::runtime_error);
  EXPECT_THROW(GetNumbersOfSum({1, 3, 1}, 3), std::runtime_error);
}