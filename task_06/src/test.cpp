
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

  data.Insert("c1", 1);
  data.Insert("c2", 2);
  data.Insert("c3", 3);
  data.Insert("c4", 4);

  ASSERT_EQ(data.Size(), 5);
  ASSERT_EQ(data.Find("aaaa"), 2);
  ASSERT_EQ(data.Find("c1"), 1);

  data.InsertOrUpdate("c1", 100);
  data.InsertOrUpdate("c6", 6);
  data.Remove("aaaa");

  ASSERT_EQ(data.Find("c1"), 100);
  ASSERT_EQ(data.Find("c3"), 3);
  ASSERT_EQ(data.Find("c4"), 4);
}