#pragma once

#include <cstddef>
#include <string>
#include <vector>

class HashTable {
 public:
  HashTable();
  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const int value);
  std::string Find(const int key) const;
  size_t Size() const;
  void Expand();
  bool Contains(int key);

 private:
  std::vector<std::vector<std::pair<std::string, int>>> data_;
};
