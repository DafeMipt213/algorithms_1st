#include "hashtable.hpp"

HashTable::HashTable() { data_ = std::vector<std::vector<Elem>>(10); }

void HashTable::Resize() {
  std::vector<std::vector<Elem>> tmp_data = std::vector<std::vector<Elem>>{};
  tmp_data.resize(2 * data_.size());
  for (int i = 0; i < data_.size(); ++i) {
    for (int j = 0; i < data_[i].size(); ++i)
      tmp_data[std::hash<std::string>{}(data_[i][j].key) % tmp_data.size()]
          .push_back(data_[i][j]);
  }
  data_ = tmp_data;
}

bool HashTable::IsInTable(const std::string& key) const {
  int i = 0;
  std::vector<Elem> curr =
      data_[(std::hash<std::string>{}(key)) % data_.size()];
  for (int i = 0; i < curr.size(); ++i)
    if (curr[i].key == key) return true;
  return false;
}

int HashTable::Find(const std::string& key) const {
  int i = 0;
  std::vector<Elem> curr =
      data_[(std::hash<std::string>{}(key)) % data_.size()];
  for (int i = 0; i < curr.size(); ++i)
    if (curr[i].key == key) return curr[i].value;
  throw std::out_of_range("No such element in hash table");
}

bool HashTable::Insert(const std::string& key, int value) {
  if (this->IsInTable(key)) return false;
  if (data_[std::hash<std::string>{}(key) % data_.size()].size() > 5)
    this->Resize();
  data_[std::hash<std::string>{}(key) % data_.size()].push_back(
      Elem(key, value));
  return true;
}

void HashTable::Remove(const std::string& key) {
  bool met = false;
  for (int i = 0;
       i < data_[std::hash<std::string>{}(key) % data_.size()].size(); ++i) {
    if (data_[std::hash<std::string>{}(key) % data_.size()][i].key == key) {
      data_[std::hash<std::string>{}(key) % data_.size()].erase(
          data_[std::hash<std::string>{}(key) % data_.size()].begin() + i);
      return;
    }
  }
  throw std::out_of_range("No such element in hash table");
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  for (int i = 0;
       i < data_[std::hash<std::string>{}(key) % data_.size()].size(); ++i) {
    if (data_[std::hash<std::string>{}(key) % data_.size()][i].key == key) {
      data_[std::hash<std::string>{}(key) % data_.size()][i].value = value;
      return;
    }
  }
  data_[std::hash<std::string>{}(key) % data_.size()].push_back(
      Elem(key, value));
}

size_t HashTable::Size() const { return data_.size(); }
