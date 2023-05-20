
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

  data.Insert("aaaa", 3);
  ASSERT_EQ(data.Find("aaaa"), 2);
  ASSERT_EQ(data.Size(), 1);

  data.Insert("test", 100);
  ASSERT_EQ(data.Find("test"), 100);
  ASSERT_EQ(data.Size(), 2);

  data.InsertOrUpdate("test", 101);
  ASSERT_EQ(data.Find("test"), 101);
  ASSERT_EQ(data.Size(), 2);

  data.Remove("test");
  ASSERT_EQ(data.Size(), 1);
}