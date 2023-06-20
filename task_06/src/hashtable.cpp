#include "hashtable.hpp"

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <string>
#include <unordered_set>

HashTable::HashTable() {
  data_ = std::vector<std::vector<std::pair<std::string, int>>>(10);
}

void HashTable::Expand() {
  std::vector<std::vector<std::pair<std::string, int>>> tmp_data =
      std::vector<std::vector<std::pair<std::string, int>>>{};
  tmp_data.resize(data_.size() * 2);
  for (int i = 0; i < data_.size(); ++i) {
    for (int j = 0; j < data_[i].size(); ++j)
      tmp_data[(std::hash<int>{}(data_[i][j].second)) % tmp_data.size()]
          .push_back(data_[i][j]);
  }
  data_ = tmp_data;
}
bool HashTable::Contains(int key) {
  int i = 0;
  const auto& curr = data_[(std::hash<int>{}(key)) % data_.size()];
  while (i < curr.size()) {
    i += 1;
    if (curr[i].second == key) {
      return true;
    }
  }
  return false;
}
bool HashTable::Insert(const std::string& value, int key) {
  if (Contains(key)) return false;
  if (data_[(std::hash<int>{}(key)) % data_.size()].size() > 5) {
    Expand();
  }
  data_[(std::hash<int>{}(key)) % data_.size()].push_back(
      std::pair<std::string, int>(value, key));
  return true;
}

void HashTable::InsertOrUpdate(const std::string& value, int key) {
  bool met = false;
  for (int i = 0; i < data_[(std::hash<int>{}(key)) % data_.size()].size();
       ++i) {
    if (data_[(std::hash<int>{}(key)) % data_.size()][i].second == key) {
      data_[(std::hash<int>{}(key)) % data_.size()][i].first = value;
      return;
    }
  }
  data_[(std::hash<int>{}(key)) % data_.size()].push_back(
      std::pair<std::string, int>(value, key));
}

void HashTable::Remove(const int key) {
  bool met = false;
  for (int i = 0; i < data_[(std::hash<int>{}(key)) % data_.size()].size();
       ++i) {
    if (data_[(std::hash<int>{}(key)) % data_.size()][i].second == key) {
      data_[(std::hash<int>{}(key)) % data_.size()].erase(
          data_[(std::hash<int>{}(key)) % data_.size()].begin() + i);
      return;
    }
  }
  throw std::out_of_range("No such element in hash table");
}
std::string HashTable::Find(const int key) const {
  int i = 0;
  std::vector<std::pair<std::string, int>> curr =
      data_[(std::hash<int>{}(key)) % data_.size()];
  while (i < curr.size()) {
    i += 1;
    if (curr[i].second == key) {
      return curr[i].first;
    }
  }
  throw std::out_of_range("No such element in hash table");
}

size_t HashTable::Size() const { return data_.size(); }
