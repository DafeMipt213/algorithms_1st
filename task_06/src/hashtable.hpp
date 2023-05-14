#pragma once

#include <cstddef>
#include <list>
#include <string>
#include <unordered_map>
#include <vector>

class HashTable {
 public:
  HashTable();
  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string& key);
  int Find(const std::string& key) const;
  size_t Size() const;
  void Rehash();

 private:
  struct KeyValue {
    std::string key;
    int value;
  };
  std::vector<std::list<KeyValue>> table;
  int counter_elems;
};
