#pragma once
#include <cstddef>
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

 private:
  struct Linked_List {
    Linked_List(std::string key, int value) : value{value}, key{key} {};
    std::string key;
    int value = 0;
    Linked_List* prev = nullptr;
    Linked_List* next = nullptr;
  };
  std::vector<Linked_List*> hash_table_;
  size_t size_ = 0;
};