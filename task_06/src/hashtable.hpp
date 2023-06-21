#include <iostream>
#include <list>
#include <vector>

template <typename KeyType, typename ValueType,
          typename HashFunc = std::hash<KeyType>>
class HashTable {
 public:
  HashTable(int size) : table(size) {}

  void Insert(const KeyType& key, const ValueType& value);
  void InsertOrUpdate(const KeyType& key, const ValueType& value);
  void Remove(const KeyType& key);
  const ValueType& Find(const KeyType& key);
  size_t Size();

 private:
  std::vector<std::list<std::pair<KeyType, ValueType>>> table;

  size_t GetIndex(const KeyType& key);
};

template <typename KeyType, typename ValueType, typename HashFunc>
void HashTable<KeyType, ValueType, HashFunc>::Insert(const KeyType& key,
                                                     const ValueType& value) {
  size_t index = GetIndex(key);
  for (auto& pair : table[index]) {
    if (pair.first == key) {
      pair.second = value;
      return;
    }
  }
  table[index].emplace_back(key, value);
}

template <typename KeyType, typename ValueType, typename HashFunc>
void HashTable<KeyType, ValueType, HashFunc>::InsertOrUpdate(
    const KeyType& key, const ValueType& value) {
  size_t index = GetIndex(key);
  for (auto& pair : table[index]) {
    if (pair.first == key) {
      pair.second = value;
      return;
    }
  }
  table[index].emplace_back(key, value);
}

template <typename KeyType, typename ValueType, typename HashFunc>
const ValueType& HashTable<KeyType, ValueType, HashFunc>::Find(
    const KeyType& key) {
  size_t index = GetIndex(key);
  for (const auto& pair : table[index]) {
    if (pair.first == key) return pair.second;
  }
  throw std::out_of_range("Key not found in hash table");
}

template <typename KeyType, typename ValueType, typename HashFunc>
void HashTable<KeyType, ValueType, HashFunc>::Remove(const KeyType& key) {
  size_t index = GetIndex(key);
  auto& bucket = table[index];
  for (auto it = bucket.begin(); it != bucket.end(); ++it) {
    if (it->first == key) {
      bucket.erase(it);
      return;
    }
  }
}

template <typename KeyType, typename ValueType, typename HashFunc>
size_t HashTable<KeyType, ValueType, HashFunc>::Size() {
  size_t count = 0;
  for (const auto& bucket : table) count += bucket.size();
  return count;
}

template <typename KeyType, typename ValueType, typename HashFunc>
size_t HashTable<KeyType, ValueType, HashFunc>::GetIndex(const KeyType& key) {
  HashFunc hashFunc;
  return hashFunc(key) % table.size();
}