#include <iostream>

#include "hashtable.hpp"

int main() {
  HashTable data;
  std::string s1 = "aaaa";
  data.Insert(s1, 1);
  std::cout << data.Find(s1) << std::endl;
  ;
  data.InsertOrUpdate(s1, 2);
  std::string s2 = "aaaa";
  std::cout << data.Find("aaaa") << std::endl;
}
