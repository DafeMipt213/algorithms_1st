
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

TEST(HashTable, EmptyTable) {
  HashTable data;
  ASSERT_EQ(data.Size(), 0);
  ASSERT_EQ(data.Find("key"), 0);
  data.Remove("key");
  ASSERT_EQ(data.Size(), 0);
}

TEST(HashTable, InsertDuplicate) {
  HashTable data;
  data.Insert("key", 1);
  ASSERT_FALSE(data.Insert("key", 2));
  ASSERT_EQ(data.Find("key"), 1);
  ASSERT_EQ(data.Size(), 1);
}

TEST(HashTable, InsertOrUpdate) {
  HashTable data;
  data.InsertOrUpdate("key", 1);
  ASSERT_EQ(data.Find("key"), 1);
  ASSERT_EQ(data.Size(), 1);

  data.InsertOrUpdate("key", 2);
  ASSERT_EQ(data.Find("key"), 2);
  ASSERT_EQ(data.Size(), 1);

  data.InsertOrUpdate("new_key", 3);
  ASSERT_EQ(data.Find("new_key"), 3);
  ASSERT_EQ(data.Size(), 2);
}

TEST(HashTable, Remove) {
  HashTable data;
  data.Insert("key1", 1);
  data.Insert("key2", 2);
  ASSERT_EQ(data.Size(), 2);

  data.Remove("key1");
  ASSERT_EQ(data.Size(), 1);
  ASSERT_EQ(data.Find("key1"), 0);
  ASSERT_EQ(data.Find("key2"), 2);
  data.Remove("nonexistent_key");
  ASSERT_EQ(data.Size(), 1);
}

TEST(HashTable, MultipleEntries) {
  HashTable data;
  data.Insert("key1", 1);
  data.Insert("key2", 2);
  data.Insert("key3", 3);
  data.Insert("key4", 4);
  data.Insert("key5", 5);
  ASSERT_EQ(data.Size(), 5);

  ASSERT_EQ(data.Find("key1"), 1);
  ASSERT_EQ(data.Find("key2"), 2);
  ASSERT_EQ(data.Find("key3"), 3);
  ASSERT_EQ(data.Find("key4"), 4);
  ASSERT_EQ(data.Find("key5"), 5);
}
