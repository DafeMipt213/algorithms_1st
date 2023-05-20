#include "hashtable.hpp"

#include <cstddef>
#include <functional>
#include <stdexcept>

int Data::Update(MyPair p) {
  for (auto& el : data_) {
    if (el.key == p.key) {
      el.val = p.val;
      return 0;
    }
  }
  Push(p);
  return 1;
}

bool Data::Push(MyPair p) {
  if (IsKeyContains(p)) {
    return false;
  } else {
    data_.push_back(p);
    return true;
  }
}

bool Data::IsKeyContains(const MyPair& pair) {
  for (auto p : data_) {
    if (p.key == pair.key) {
      return true;
    }
  }
  return false;
}

int Data::Get() {
  if (data_.empty()) {
    throw std::out_of_range("out of range");
  }
  return data_.back().val;
}

int Data::Remove(const std::string& key) {
  if (data_.empty()) throw std::runtime_error("out of range");
  int temp = data_.back().val;
  data_.pop_back();
  return temp;
}

int HashTable::Hash(const std::string& key) const {
  return std::hash<std::string>{}(key) % data_.size();
}

HashTable::HashTable() { data_.resize(1000); }

bool HashTable::Insert(const std::string& key, int value) {
  bool is_success = data_[Hash(key)].Push(MyPair(key, value));
  size += is_success;
  return is_success;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  size += data_[Hash(key)].Update(MyPair(key, value));
}

void HashTable::Remove(const std::string& key) {
  size--;
  data_[Hash(key)].Remove(key);
}

int HashTable::Find(const std::string& key) { return data_[Hash(key)].Get(); }

size_t HashTable::Size() const { return size; }
