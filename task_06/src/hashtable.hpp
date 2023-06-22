#pragma once

#include <algorithm>
#include <list>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

class HashTable {
 public:
  HashTable();
  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string& key);
  int Find(const std::string& key) const;

 private:
  std::vector<std::list<std::pair<std::string, int>>> data_;
  size_t Hash(const std::string& key) const;
  void ReHash();
  size_t size = 0;
};
