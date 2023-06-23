#pragma once

#include <cstddef>
#include <string>
#include <vector>

struct Elem {
  Elem(std::string&& key, int value) : key_in(key), value_in(value) {}
  std::string key_in;
  int value_in;
  Elem* next_elem = nullptr;
};

class HashTable {
 public:
  HashTable();
  bool Insert(const std::string&& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string&& key);
  int Find(const std::string&& key) const;
  size_t Size() const;

 private:
  bool contains(const std::string&& key);
  std::vector<Elem*> table;
  std::size_t size = 0;
};
