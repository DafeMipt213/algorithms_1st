#include "hashtable.hpp"

#include <functional>
#include <stdexcept>

int HashTable::Data::Update(HashTable::Data::KeyValue key_value) {
  for (auto& elem : data_) {
    if (elem.GetKey() == key_value.GetKey()) {
      elem.SetValue(key_value.GetValue());
      return 0;
    }
  }
  Push(key_value);
  return 1;
}

bool HashTable::Data::Push(HashTable::Data::KeyValue new_key_value) {
  if (IsKeyContains(new_key_value)) {
    return false;
  } else {
    data_.push_back(new_key_value);
    return true;
  }
}

bool HashTable::Data::IsKeyContains(
    const HashTable::Data::KeyValue& key_value) const {
  for (auto& elem : data_) {
    if (elem.GetKey() == key_value.GetKey()) {
      return true;
    }
  }
  return false;
}

int HashTable::Data::GetValue(const std::string& key) const {
  if (data_.empty()) {
    throw std::out_of_range("no data in table");
  }
  for (auto& elem : data_) {
    if (elem.GetKey() == key) {
      return elem.GetValue();
    }
  }
  throw std::out_of_range("no data in table");
}

int HashTable::Data::Remove(const std::string& key) {
  if (data_.empty()) throw std::runtime_error("no data in table");
  int temp = data_.back().GetValue();
  data_.pop_back();
  return temp;
}

HashTable::Data::KeyValue HashTable::Data::GetKeyValue(size_t index) {
  return data_[index];
}

void HashTable::Data::Pop(size_t index) { data_.erase(data_.begin() + index); }

int HashTable::Hash(const std::string& key) const {
  return std::hash<std::string>{}(key) % data_.size();
}

HashTable::HashTable() { data_.resize(500); }

bool HashTable::Insert(const std::string& key, int value) {
  bool is_success = data_[Hash(key)].Push(Data::KeyValue(key, value));
  element_count += is_success;
  Rehash();
  return is_success;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  element_count += data_[Hash(key)].Update(Data::KeyValue(key, value));
  Rehash();
}

void HashTable::Remove(const std::string& key) {
  data_[Hash(key)].Remove(key);
  element_count--;
}

int HashTable::Find(const std::string& key) const {
  return data_[Hash(key)].GetValue(key);
}

size_t HashTable::Size() const { return element_count; }

void HashTable::Rehash() {
  if ((float)element_count / (float)data_.size() > 0.7) {
    data_.resize(data_.size() * 2);
    for (auto& data : data_) {
      size_t s = data.Size();
      for (size_t i = 0; i < s; ++i) {
        HashTable::Data::KeyValue temp = data.GetKeyValue(0);
        data.Pop(0);
        data_[Hash(temp.GetKey())].Push(temp);
      }
    }
  }
}