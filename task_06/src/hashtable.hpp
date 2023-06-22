#pragma once

#include <iostream>
#include <vector>

class Elem {
 public:
  std::string key;  // check!
  int value;
  Elem(const std::string& k, int v) {
    key = k;
    value = v;
  }
};

class HashTable {
 public:
  HashTable();
  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string& key);
  int Find(const std::string& key) const;
  void Resize();
  bool IsInTable(const std::string& key) const;
  size_t index(const std::string& key) {
    return std::hash<std::string>{}(key) % data_.size();
  }
  size_t Size() const;

 private:
  std::vector<std::vector<Elem>> data_;
};
