#pragma once

#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

class HashTable {
 public:
  HashTable();
  ~HashTable();
  bool Insert(const std::string &key, int value);
  void InsertOrUpdate(const std::string &key, int value);
  void Remove(const std::string &key);
  int Find(const std::string &key) const;
  size_t Size() const;

 private:
  struct Node {
    std::string key;
    int value;
    Node *next;

    Node(const std::string &k, int v) : key(k), value(v), next(nullptr) {}
  };
  const int TABLE_SIZE = 11;
  size_t GetHash(const std::string &key) const;
  std::vector<Node *> table;
  size_t size = 0;
};
