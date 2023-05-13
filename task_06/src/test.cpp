
#include <gtest/gtest.h>

#include <vector>

#include "hashtable.hpp"

TEST(HashTable, Simple) {
  HashTable data;
  data.Insert("aaaa", 1);
  ASSERT_EQ(data.Find("aaaa"), 1);
  ASSERT_EQ(data.Size(), 1);
  data.InsertOrUpdate("aaaa", 2);
  ASSERT_EQ(data.Find("aaaa"), 2);
  ASSERT_EQ(data.Size(), 1);
  data.Remove("aaaa");
  ASSERT_EQ(data.Size(), 0);
}
TEST(HashTable, Even) {
  HashTable data;
  data.Insert("aaaa", 1);
  data.Insert("vvvv", 2);
  data.InsertOrUpdate("aaaa", 3);
  data.Insert("bbbb", 4);
  ASSERT_EQ(data.Size(), 3);
  ASSERT_EQ(data.Find("aaaa"), 3);
  data.Remove("bbbb");
  ASSERT_EQ(data.Size(), 2);
  ASSERT_EQ(data.Find("vvvv"), 2);
}