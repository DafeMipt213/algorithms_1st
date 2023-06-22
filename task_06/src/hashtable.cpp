#include <cstddef>
#include <stdexcept>
#include <string>
#include <vector>

class HashTable {
 public:
  static const size_t TABLE_SIZE = 100;

  HashTable();
  ~HashTable();

  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string& key);
  int Find(const std::string& key) const;
  size_t Size() const;

 private:
  struct HashNode {
    std::string key;
    int value;
    bool occupied;

    HashNode() : occupied(false) {}
  };

  std::vector<HashNode> table_;

  size_t Hash(const std::string& key) const;
};

HashTable::HashTable() : table_(TABLE_SIZE) {}

HashTable::~HashTable() {}

size_t HashTable::Hash(const std::string& key) const {
  size_t hash = 0;
  for (char c : key) {
    hash = (hash * 31 + c) % TABLE_SIZE;
  }
  return hash;
}

bool HashTable::Insert(const std::string& key, int value) {
  size_t hash = Hash(key);
  size_t initialIndex = hash;

  while (table_[hash].occupied) {
    if (table_[hash].key == key) {
      return false;  // Key already exists
    }
    hash = (hash + 1) % TABLE_SIZE;
    if (hash == initialIndex) {
      throw std::out_of_range("Hash table is full");
    }
  }

  table_[hash].key = key;
  table_[hash].value = value;
  table_[hash].occupied = true;

  return true;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  size_t hash = Hash(key);
  size_t initialIndex = hash;

  while (table_[hash].occupied) {
    if (table_[hash].key == key) {
      table_[hash].value = value;
      return;
    }
    hash = (hash + 1) % TABLE_SIZE;
    if (hash == initialIndex) {
      throw std::out_of_range("Hash table is full");
    }
  }

  table_[hash].key = key;
  table_[hash].value = value;
  table_[hash].occupied = true;
}

void HashTable::Remove(const std::string& key) {
  size_t hash = Hash(key);
  size_t initialIndex = hash;

  while (table_[hash].occupied) {
    if (table_[hash].key == key) {
      // Удаляем элемент из таблицы
      table_[hash].occupied = false;
      return;
    }
    hash = (hash + 1) % TABLE_SIZE;
    if (hash == initialIndex) {
      return;  // Элемент не найден
    }
  }
}

int HashTable::Find(const std::string& key) const {
  size_t hash = Hash(key);
  size_t initialIndex = hash;

  while (table_[hash].occupied) {
    if (table_[hash].key == key) {
      return table_[hash].value;
    }
    hash = (hash + 1) % TABLE_SIZE;
    if (hash == initialIndex) {
      break;  // Элемент не найден
    }
  }

  throw std::out_of_range("Key not found");
}

size_t HashTable::Size() const {
  size_t count = 0;
  for (const auto& node : table_) {
    if (node.occupied) {
      count++;
    }
  }
  return count;
}
