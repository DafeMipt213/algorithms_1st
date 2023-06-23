#include "hashtable.hpp"

#include <cstddef>
#include <string>

HashTable::HashTable() {}

bool HashTable::contains(const std::string&& key) {
  for (int i = 0; i < size; i++) {
    if (table[i]->key_in == key) {
      return true;
    }
  }
  return false;
}

bool HashTable::Insert(const std::string&& key, int value) {
  if (contains(key)) return false;
  table[size] = new Elem(std::move(key), value);
  ++size;
  return true;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  for (int i = 0; i < size; i++) {
    if (table[i]->key_in == key) {
      Elem* temp = table[i];
      while (temp->next_elem != nullptr) {
        temp = temp->next_elem;
      }
      temp->next_elem = new Elem(std::move(key), value);
      ++size;
    }
    break;
  }
  Insert(std::move(key), value);
  ++size;
}

void HashTable::Remove(const std::string& key) {
  for (int i = 0; i < size; i++) {
    if (table[i]->key_in == key) {
      Elem* temp = table[i];
      if (temp->next_elem == nullptr) {
        table.erase(table.begin() + i);
        --size;
        break;
      } else {
        while (temp->next_elem->next_elem != nullptr) {
          temp = temp->next_elem;
        }
        Elem* to_del = temp->next_elem;
        temp->next_elem = nullptr;
        delete to_del;
        --size;
        break;
      }
    }
  }
}

int HashTable::Find(const std::string& key) const {
  for (int i = 0; i < size; i++) {
    if (table[i]->key_in == key) {
      Elem* temp = table[i];
      if (temp->next_elem == nullptr) {
        return temp->value_in;
      } else {
        while (temp->next_elem != nullptr) {
          temp = temp->next_elem;
        }
        return temp->value_in;
      }
    }
  }
  return -1;
}

size_t HashTable::Size() const { return size; }