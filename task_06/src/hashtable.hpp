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
  struct LinkedList {
    LinkedList(std::string key, int value) : value{value}, key{key} {};
    std::string key;
    int value = 0;
    LinkedList* prev = nullptr;
    LinkedList* next = nullptr;
  };
  std::vector<LinkedList*> hash_table_;
  size_t size_ = 0;
};