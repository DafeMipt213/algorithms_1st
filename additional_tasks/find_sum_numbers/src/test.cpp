
#include <gtest/gtest.h>

#include <stack>

#include "utils.hpp"

TEST(GetNumbersOfSum, Simple) {
  ASSERT_EQ(GetNumbersOfSum({-10, -20, 0, 3, 6, 7, 11, 14}, 3),
            (std::pair{2, 3}));
}
TEST(GetNumbersOfSum, Empty) {
  ASSERT_EQ(GetNumbersOfSum({}, 3), (std::pair{-1, -1}));
}
TEST(GetNumbersOfSum, Hard) {
  ASSERT_EQ(GetNumbersOfSum({-10, -9, -8, -7}, 3), (std::pair{-1, -1}));
}
TEST(GetNumbersOfSum, Complex) {
  ASSERT_EQ(GetNumbersOfSum({0, 1, 2, 2, 3, 4, 5}, 4), (std::pair{0, 5}));
}