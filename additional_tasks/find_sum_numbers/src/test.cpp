
#include <gtest/gtest.h>

#include <utility>

#include "utils.hpp"

TEST(GetNumbersOfSum, Simple) {
  std::vector<int> v;
  ASSERT_EQ(GetNumbersOfSum({-10, -2, 0, 3, 6, 7, 11, 14}, 3),
            (std::pair<int, int>{0, 3}));
  ASSERT_EQ(GetNumbersOfSum({0, 0}, 3), (std::pair<int, int>{}));
  ASSERT_EQ(GetNumbersOfSum({-10, -2, 0, 3, 6, 7, 11, 14}, 4),
            (std::pair<int, int>{-10, 14}));
  ASSERT_EQ(GetNumbersOfSum({-10, -2, 0, 3, 6, 7, 11, 14}, 1000),
            (std::pair<int, int>{}));
  ASSERT_EQ(GetNumbersOfSum({4}, 3), (std::pair<int, int>{}));
}