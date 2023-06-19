#include <hashtable.hpp>
#include <iostream>
int main() {
  HashTable a;
  a.Insert("first", 3);
  a.InsertOrUpdate("second", 4);
  a.InsertOrUpdate("third", 5);
  a.Remove("first");
  std::cout << a.Size();
  return 0;
}
