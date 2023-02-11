
#include <gtest/gtest.h>

#include <vector>

#include "utils.hpp"

TEST(HashTable, Simple) {
  ASSERT_EQ(data.Find("aaaa"), 1);
  data.InsertOrUpdate("aaaa", 2);
  ASSERT_EQ(data.Find("aaaa"), 2);
}