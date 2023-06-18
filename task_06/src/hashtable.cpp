#include "hashtable.hpp"

namespace {
bool is_eq(const std::string& s1, const std::string& s2) {
  if (s1.size() != s2.size()) return false;
  for (size_t i = 0; i < s1.size(); ++i)
    if (s1[i] != s2[i]) return false;
  return true;
}
}  // namespace

HashTable::HashTable() : data_(8) {}

size_t HashTable::Hash(const std::string& key) const {
  size_t index = 0;
  for (char c : key) {
    index += (size_t)(c);
    index %= Size();
  }
  return index;
}

bool HashTable::Insert(const std::string& key, int value) {
  size_t index = Hash(key);
  for (auto elem : data_[index])
    if (is_eq(key, elem.first)) return false;
  ReHash();
  data_[index].push_back(std::pair<std::string, int>(key, value));
  return true;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  size_t index = Hash(key);
  for (auto& elem : data_[index])
    if (is_eq(key, elem.first)) {
      elem.second = value;
      return;
    }
  ReHash();
  data_[index].push_back(std::pair<std::string, int>(key, value));
}

void HashTable::Remove(const std::string& key) {
  data_[Hash(key)].remove_if([key](const std::pair<std::string, int>& elem) {
    return is_eq(key, elem.first);
  });
}

int HashTable::Find(const std::string& key) const {
  for (auto elem : data_[Hash(key)])
    if (is_eq(key, elem.first)) return elem.second;
  throw std::out_of_range(
      "HashTable::Find : there is no element with such key");
}

void HashTable::ReHash() {
  std::vector<std::list<std::pair<std::string, int>>> tmp(2 * Size());
  std::swap(data_, tmp);
  for (auto list : tmp)
    for (auto elem : list) {
      Insert(elem.first, elem.second);
      list.clear();
    }
  tmp.clear();
}

size_t HashTable::Size() const { return data_.size(); }
