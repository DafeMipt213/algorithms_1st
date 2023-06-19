#include "hashtable.hpp"

#include <cstddef>
#include <string>

HashTable::HashTable() {
  data_.resize(100);
  table_size_ = 100;
}

int MyHashFunction(const std::string& s, int table_size) {
  int k = table_size - 1;
  int hash_result = 0;
  for (size_t i = 0; i <= s.size(); ++i)
    hash_result = (k * hash_result + s[i]) % table_size;
  hash_result = (hash_result * 2 + 1) % table_size;
  return hash_result;
}

int HashFunction1::operator()(const std::string& s, int tableSize) const {
  return MyHashFunction(s, tableSize);
}

bool Elem::operator==(Elem el) {
  if (key_ == el.key_ && value_ == el.value_) return true;
  return false;
}

bool HashTable::Insert(const std::string& key, int value) {
  int index = HashFunction1()(key, data_.size());
  Elem obj(key, value);
  if (InTable(obj)) return false;
  data_[index].push_back(obj);
  return true;
}

bool HashTable::InTable(Elem el) {
  int index = HashFunction1()(el.key_, data_.size());
  for (const auto& item : data_[index])
    if (item.key_ == el.key_) return true;
  return false;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  int index = HashFunction1()(key, data_.size());
  Elem obj(key, value);
  if (!InTable(obj)) {
    Insert(key, value);
    return;
  }

  for (size_t i = 0; i < data_[index].size(); ++i) {
    if (data_[index][i].key_ == obj.key_) {
      data_[index][i].value_ = obj.value_;
      break;
    }
  }
  return;
}

void HashTable::Remove(const std::string& key) {
  int index = HashFunction1()(key, table_size_);
  for (size_t i = 0; i < data_[index].size(); ++i) {
    if (data_[index][i].key_ == key) {
      data_[index].erase(data_[index].begin() + i);
    }
  }
  return;
}

int HashTable::Find(const std::string& key) const {
  int index = HashFunction1()(key, table_size_);
  for (size_t i = 0; i < data_[index].size(); ++i) {
    if (data_[index][i].key_ == key) {
      return data_[index][i].value_;
    }
  }
}

size_t HashTable::Size() const { return table_size_; }

void HashTable::PrintTable() {
  for (size_t i = 0; i < data_.size(); i++) {
    for (size_t j = 0; j < data_[i].size(); j++)
      std::cout << data_[i][j].value_;
  }
}