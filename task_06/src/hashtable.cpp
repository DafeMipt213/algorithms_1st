#include "hashtable.hpp"
#include <algorithm>

HashTable::HashTable() { data_.resize(kTableSize); }

std::string KeyValue::getKey() const { return key; }

int KeyValue::getValue() const { return value; }

void KeyValue::setKey(std::string newKey) { key = newKey; }

void KeyValue::setValue(int newValue) { value = newValue; }

bool HashTable::Insert(const std::string &key, int value) {
  size_t index = HashFunction(key);
  std::vector<KeyValue> &bucket = data_[index];
  for (const auto &entry : bucket) {
    if (entry.getKey() == key) {
      return false;
    }
  }
  bucket.emplace_back(key, value);
  return true;
}

void HashTable::InsertOrUpdate(const std::string &key, int value) {
  size_t index = HashFunction(key);
  std::vector<KeyValue> &bucket = data_[index];
  for (auto &entry : bucket) {
    if (entry.getKey() == key) {
      entry.setValue(value);
      return;
    }
  }
  bucket.emplace_back(key, value);
}

void HashTable::Remove(const std::string &key) {
  size_t index = HashFunction(key);
  std::vector<KeyValue> &bucket = data_[index];
  auto it =
      std::find_if(bucket.begin(), bucket.end(), [&key](const KeyValue &entry) {
        return entry.getKey() == key;
      });
  if (it != bucket.end()) {
    bucket.erase(it);
  }
}

int HashTable::Find(const std::string &key) const {
  size_t index = HashFunction(key);
  const std::vector<KeyValue> &bucket = data_[index];
  for (const auto &entry : bucket) {
    if (entry.getKey() == key) {
      return entry.getValue();
    }
  }
  return 0;
}

size_t HashTable::Size() const {
  size_t count = 0;
  for (const auto &bucket : data_) {
    count += bucket.size();
  }
  return count;
}

size_t HashTable::HashFunction(const std::string &key) const {
  size_t hash = 0;
  for (char ch : key) {
    hash = (hash * 31 + ch) % kTableSize;
  }
  return hash;
}