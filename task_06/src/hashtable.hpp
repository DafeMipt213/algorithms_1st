#pragma once

#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>

struct MyPair {
  MyPair(std::string k, int v) : key{k}, val{v} {}
  std::string key;
  int val;
};

class Data {
 public:
  bool Push(MyPair);
  int Update(MyPair);
  int Get();
  int Remove(const std::string& key);

 private:
  bool IsKeyContains(const MyPair& pair);
  std::vector<MyPair> data_;
};

class HashTable {
 public:
  HashTable();
  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string& key);
  int Find(const std::string& key);
  size_t Size() const;

 private:
  void Rehash();
  int Hash(const std::string& key) const;
  std::vector<Data> data_;
  size_t size = 0;
};