#include <iostream>

#include "hashtable.hpp"

int main() {
  HashTable hashTable;

  // Insert
  hashTable.Insert("apple", 5);
  std::cout << hashTable.Insert("banana", 10) << std::endl;

  // InsertOrUpdate
  hashTable.InsertOrUpdate("apple", 8);
  hashTable.InsertOrUpdate("banana", 12);
  hashTable.InsertOrUpdate("durian", 20);

  // Find
  std::cout << "Value of apple: " << hashTable.Find("apple") << std::endl;
  std::cout << "Value of banana: " << hashTable.Find("banana") << std::endl;

  std::cout << "Value of durian: " << hashTable.Find("durian") << std::endl;

  // Remove
  hashTable.Remove("apple");
  hashTable.Remove("banana");
  hashTable.Remove("durian");
  hashTable.Remove("durian");

  // Size
  std::cout << "Size of hash table: " << hashTable.Size() << std::endl;

  return 0;
}
