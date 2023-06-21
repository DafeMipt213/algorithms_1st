
#include <gtest/gtest.h>

#include <vector>

#include "hashtable.hpp"

TEST(HashTable, Simple_1) {
  HashTable data;
  data.Insert("aaaa", 1);
  ASSERT_EQ(data.Find("aaaa"), 1);
  ASSERT_EQ(data.Size(), 1);
  data.InsertOrUpdate("aaaa", 2);
  ASSERT_EQ(data.Find("aaaa"), 2);
  ASSERT_EQ(data.Size(), 1);
}



TEST(HashTable, test_2) {
  // TABLE_SIZE = 11
  HashTable data;
  data.Insert("aaaa", 1);
  data.Insert("bbbb", 2);
  data.Insert("cccc", 3);
  data.Insert("dddd", 4);
  data.Insert("eeee", 5);
  data.Insert("ffff", 6);
  data.Insert("gggg", 7);
  data.Insert("hhhh", 8);
  data.Insert("iiii", 9);
  data.Insert("jjjj", 10);
  data.Insert("kkkk", 11);
  data.Insert("llll", 12);
  ASSERT_EQ(data.Size(), 12);
  ASSERT_EQ(data.Find("aaaa"), 1);
  ASSERT_EQ(data.Find("bbbb"), 2);
  ASSERT_EQ(data.Find("cccc"), 3);
  ASSERT_EQ(data.Find("dddd"), 4);
  ASSERT_EQ(data.Find("eeee"), 5);
  ASSERT_EQ(data.Find("ffff"), 6);
  data.InsertOrUpdate("aaaa", 10);
  data.InsertOrUpdate("bbbb", 20);
  data.InsertOrUpdate("cccc", 30);
  data.InsertOrUpdate("dddd", 40);
  data.InsertOrUpdate("eeee", 50);
  data.InsertOrUpdate("ffff", 60);
  data.InsertOrUpdate("gggg", 70);
  data.InsertOrUpdate("hhhh", 80);
  data.InsertOrUpdate("iiii", 90);
  data.InsertOrUpdate("jjjj", 100);
  data.InsertOrUpdate("kkkk", 110);
  data.InsertOrUpdate("llll", 120);
  ASSERT_EQ(data.Find("aaaa"), 10);
  ASSERT_EQ(data.Find("bbbb"), 20);
  ASSERT_EQ(data.Find("cccc"), 30);
  ASSERT_EQ(data.Find("dddd"), 40);
  ASSERT_EQ(data.Find("llll"), 120);
  ASSERT_EQ(data.Size(), 12);
}