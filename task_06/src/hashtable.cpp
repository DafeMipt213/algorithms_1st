#include "hashtable.hpp"

#include <cstddef>
#include <string>
HashTable::HashTable() {
table.resize(TABLE_SIZE, nullptr);
}
HashTable::~HashTable() {
for (Node *bucket : table) {
while (bucket) {
Node *temp = bucket;
bucket = bucket->next;
delete temp;
}
}
}
bool HashTable::Insert(const std::string &key, int value) {
size_t index = GetHash(key);
Node *node = table[index];
while (node) {
if (node->key == key) {
return false; 
}
node = node->next;
}
Node *newNode = new Node(key, value);
newNode->next = table[index];
table[index] = newNode;
size++;
return true;
}
void HashTable::InsertOrUpdate(const std::string &key, int value) {
size_t index = GetHash(key);
Node *node = table[index];
while (node) {
if (node->key == key) {
node->value = value;
return;
}
node = node->next;
}
Node *newNode = new Node(key, value);
newNode->next = table[index];
table[index] = newNode;
size++;
}
void HashTable::Remove(const std::string &key) {
size_t index = GetHash(key);
Node *node = table[index];
Node *prevNode = nullptr;
while (node) {
if (node->key == key) {
if (prevNode) {
prevNode->next = node->next;
} else {
table[index] = node->next;
}
delete node;
size--;
return;
}
prevNode = node;
node = node->next;
}
}
int HashTable::Find(const std::string &key) const {
size_t index = GetHash(key);
Node *node = table[index];
while (node) {
if (node->key == key) {
return node->value;
}
node = node->next;
}
return 0;
}
size_t HashTable::Size() const {
return size;
}
size_t HashTable::GetHash(const std::string &key) const {
size_t hashCode = 0;
for (char ch : key) {
hashCode = (hashCode * 31 + ch) % TABLE_SIZE;
}
return hashCode;
}