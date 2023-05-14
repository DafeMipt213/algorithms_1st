#include "hashtable.hpp"

#include <cstddef>
#include <exception>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>

HashTable::HashTable() {}

void HashTable::Rehash() {
  if (table.size() == 0 || ((table.size() - counter_elems) % table.size() >=
                            int(table.size() * 0.7))) {
    std::vector<std::list<KeyValue>> new_table;
    new_table.resize((table.size() + 1) * 2);
    int new_hashed_key;
    for (size_t i = 0; i < table.size(); i++) {
      for (auto list_kv = table[i].begin(); list_kv != table[i].end();
           ++list_kv) {
        new_hashed_key =
            std::hash<std::string>{}(list_kv->key) % new_table.size();
        new_table[new_hashed_key].push_back(std::move(*list_kv));
      }
    }
    table = std::move(new_table);
  }
}

bool HashTable::Insert(const std::string& key, int value) {
  this->Rehash();
  int hashed_key = std::hash<std::string>{}(key) % table.size();
  for (auto list_kv = table[hashed_key].begin();
       list_kv != table[hashed_key].end(); ++list_kv) {
    if (list_kv->key == key) return false;
  }
  KeyValue kv;
  kv.key = key;
  kv.value = value;
  table[hashed_key].push_back(kv);
  this->counter_elems += 1;
  return true;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  this->Rehash();
  int hashed_key = std::hash<std::string>{}(key) % table.size();
  for (auto list_kv = table[hashed_key].begin();
       list_kv != table[hashed_key].end(); ++list_kv) {
    if (list_kv->key == key) {
      list_kv->value = value;
      return;
    }
  }
  KeyValue kv;
  kv.key = key;
  kv.value = value;
  table[hashed_key].push_back(kv);
  this->counter_elems += 1;
  return;
}

void HashTable::Remove(const std::string& key) {
  int hashed_key = std::hash<std::string>{}(key) % table.size();
  if (table[hashed_key].empty()) throw std::out_of_range("Empty HashTable");

  for (auto list_kv = table[hashed_key].begin();
       list_kv != table[hashed_key].end(); ++list_kv) {
    if (list_kv->key == key) {
      table[hashed_key].erase(list_kv);
      this->counter_elems -= 1;
      return;
    }
  }
  throw std::out_of_range("No element in HashTable");
}

int HashTable::Find(const std::string& key) const {
  int hashed_key = std::hash<std::string>{}(key) % table.size();
  for (auto list_kv = table[hashed_key].begin();
       list_kv != table[hashed_key].end(); ++list_kv) {
    if (list_kv->key == key) {
      return list_kv->value;
    }
  }
  throw std::out_of_range("No element in HashTable");
}

size_t HashTable::Size() const { return this->counter_elems; }
