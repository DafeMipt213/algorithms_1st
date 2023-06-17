
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
}

TEST(HashTable, Basic) {
  HashTable data;
  data.Insert("a", 11);
  ASSERT_EQ(data.Size(), 1);
  data.Insert("b", 22);
  ASSERT_EQ(data.Size(), 2);
  data.Insert("c", 33);
  ASSERT_EQ(data.Size(), 3);
  ASSERT_EQ(data.Find("a"), 11);
  ASSERT_EQ(data.Find("b"), 22);
  data.Remove("a");
  ASSERT_EQ(data.Size(), 2);
  data.InsertOrUpdate("c", 16);
  data.InsertOrUpdate("a", 100);
  ASSERT_EQ(data.Find("a"), 100);
  ASSERT_EQ(data.Find("c"), 16);
}

TEST(HashTable, Exceptions) {
  HashTable data;
  data.Insert("a", 11);
  data.Insert("a", 22);
  data.Insert("a", 33);
  data.Remove("a");
  ASSERT_ANY_THROW(data.Find("a"));
  data.Remove("a");
  ASSERT_EQ(data.Size(), 2);
}