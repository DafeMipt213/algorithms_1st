
#include <gtest/gtest.h>

#include <vector>

#include "hashtable.hpp"

TEST(HashTable, Simple) {
  HashTable data;
  data.Insert("aaaa", 1);
  ASSERT_EQ(data.Find("aaaa"), 1);
  data.InsertOrUpdate("aaaa", 2);
  ASSERT_EQ(data.Find("aaaa"), 2);
}

TEST(HashTable, Basic) {
  HashTable data;
  data.Insert("aaa", 11);
  data.Insert("bb", 22);
  data.Insert("c", 33);
  ASSERT_EQ(data.Find("aaa"), 11);
  ASSERT_EQ(data.Find("bb"), 22);
  data.Remove("aaa");
  data.InsertOrUpdate("c", 16);
  data.InsertOrUpdate("aaa", 100);
  ASSERT_EQ(data.Find("aaa"), 100);
  ASSERT_EQ(data.Find("c"), 16);
}

TEST(HashTable, Exceptions) {
  HashTable data;
  data.Insert("ab", 11);
  data.Insert("ab", 22);
  data.Insert("ab", 33);
  data.Remove("ab");
  ASSERT_ANY_THROW(data.Find("ab"));
  data.Remove("ab");
}