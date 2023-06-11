#include "hashtable.hpp"

#include <cstddef>
#include <string>

HashTable::HashTable() { table.resize(TABLE_SIZE, nullptr); }
HashTable::~HashTable() {
  for (Node *bucket : table) {
    while (bucket) {
      Node *temp = bucket;
      bucket = bucket->next;
      delete temp;
    }
  }
}

size_t HashTable::GetHash(const std::string &key) const {
  size_t hash = 0;
  for (char ch : key) hash = (hash * 31 + ch) % TABLE_SIZE;
  return hash;
}

bool HashTable::Insert(const std::string &key, int value) {
  size_t index = GetHash(key);
  Node *new_node = new Node(key, value);

  if (!table[index]) {
    table[index] = new_node;
  } else {
    Node *current = table[index];
    while (current) {
      if (current->key == key) return false;  // Key already exists
      if (!current->next) break;
      current = current->next;
    }
    current->next = new_node;
  }
  size++;
  return true;
}

void HashTable::InsertOrUpdate(const std::string &key, int value) {
  size_t index = GetHash(key);

  if (!table[index]) {
    table[index] = new Node(key, value);
    size++;
  } else {
    Node *current = table[index];
    while (current) {
      if (current->key == key) {
        current->value = value;
        return;
      }
      if (!current->next) break;
      current = current->next;
    }
    current->next = new Node(key, value);
    size++;
  }
}

void HashTable::Remove(const std::string &key) {
  if (size == 0) throw std::out_of_range("Remove error - size=0");
  size_t index = GetHash(key);

  if (!table[index]) return;

  Node *current = table[index];
  Node *prev = nullptr;

  while (current) {
    if (current->key == key) {
      if (prev)
        prev->next = current->next;
      else
        table[index] = current->next;
      delete current;
      size--;
      return;
    }
    prev = current;
    current = current->next;
  }
}

int HashTable::Find(const std::string &key) const {
  size_t index = GetHash(key);

  Node *current = table[index];
  while (current) {
    if (current->key == key) return current->value;
    current = current->next;
  }
  throw std::out_of_range("Key not found for \"" + key + "\"");
}

size_t HashTable::Size() const { return size; }