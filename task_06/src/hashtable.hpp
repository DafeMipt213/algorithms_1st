#pragma once

#include <string>

class HashTable {
 public:
  HashTable() : bufferSize(8), elementCount(0) {
    table = new Node*[bufferSize];
    for (size_t i = 0; i < bufferSize; i++) table[i] = nullptr;
  }
  ~HashTable() {
    for (int i = 0; i < bufferSize; ++i)
      if (table[i] != nullptr) delete table[i];
    delete[] table;
  }

  bool Insert(const std::string& key, int value);
  bool Remove(const std::string& key);
  void InsertOrUpdate(const std::string& key, int value);
  int Find(const std::string& key);
  [[nodiscard]] int Size() const { return elementCount; };

 private:
  struct Node {
    std::string data;
    int value;
    bool deleted;
    explicit Node(std::string key, int value)
        : data(move(key)), value(value), deleted(false) {}
  };
  void rehash();
  [[nodiscard]] bool contains(const std::string& key) const;
  [[nodiscard]] int hash(const std::string& key) const;
  int bufferSize;
  int elementCount;
  constexpr static double fillFactor = 3.0 / 4.0;
  Node** table;
};
