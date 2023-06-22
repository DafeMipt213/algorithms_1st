#include "hashtable.hpp"

bool HashTable::Insert(const std::string& key, int value) {
  if (fillFactor <= (elementCount + 1 + 0.0) / bufferSize) rehash();

  int hashKey = hash(key);
  int step = 0;
  while (step < bufferSize) {
    if (table[hashKey] == nullptr) {
      table[hashKey] = new Node(key, value);
      elementCount++;
      return true;
    } else if (table[hashKey]->data == key) {
      table[hashKey]->deleted = false;
      table[hashKey]->value = value;
      return true;
    } else if (table[hashKey]->deleted) {
      table[hashKey]->data = key;
      table[hashKey]->deleted = false;
      elementCount++;
      return true;
    }
    step++;
    hashKey = (hashKey + step) % bufferSize;
  }
  return false;
}

bool HashTable::contains(const std::string& key) const {
  int hashed = hash(key);
  int step = 0;
  while (table[hashed] != nullptr && step < bufferSize) {
    if (!table[hashed]->deleted && table[hashed]->data == key) return true;
    step++;
    hashed = (hashed + step) % bufferSize;
  }
  return false;
}

bool HashTable::Remove(const std::string& key) {
  if (!contains(key)) return false;

  int hashed = hash(key);

  int step = 0;
  while (step < bufferSize) {
    if (!table[hashed]->deleted && table[hashed]->data == key) {
      table[hashed]->deleted = true;
      elementCount--;
      return true;
    }
    step++;
    hashed = (hashed + step) % bufferSize;
  }
  return false;
}

void HashTable::rehash() {
  Node** tmp = table;
  bufferSize *= 2;
  elementCount = 0;
  table = new Node*[bufferSize];

  for (int i = 0; i < bufferSize; i++) table[i] = nullptr;

  for (int i = 0; i < bufferSize / 2; i++)
    if (tmp[i] != nullptr) {
      if (!tmp[i]->deleted) Insert(tmp[i]->data, tmp[i]->value);
      delete tmp[i];
    }

  delete[] tmp;
}

int HashTable::hash(const std::string& key) const {
  int hashed = 0;
  for (char i : key) {
    hashed = (hashed + 127 * i) % bufferSize;
  }
  return hashed;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  bool f = Insert(key, value);
}

int HashTable::Find(const std::string& key) {
  int hashed = hash(key);
  int step = 0;
  while (table[hashed] != nullptr && step < bufferSize) {
    if (!table[hashed]->deleted && table[hashed]->data == key)
      return table[hashed]->value;
    step++;
    hashed = (hashed + step) % bufferSize;
  }
  return false;
}
