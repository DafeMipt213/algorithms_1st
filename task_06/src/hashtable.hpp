#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int MyHashFunction(const std::string& s, int tableSize);

struct HashFunction1 {
  int operator()(const std::string& s, int tableSize) const;
};

class Elem {
 public:
  std::string key_;
  int value_;
  Elem() = default;
  Elem(std::string key, int value) : key_{key}, value_{value} {}
  bool operator==(Elem el);
};

class HashTable {
 public:
  HashTable();
  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string& key);
  int Find(const std::string& key) const;
  bool InTable(Elem el);
  size_t Size() const;
  void PrintTable();

 private:
  std::vector<std::vector<Elem>> data_;
  size_t TableSize;
};