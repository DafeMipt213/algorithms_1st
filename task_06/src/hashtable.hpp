// #pragma once

// #include <list>
// #include <string>
// #include <vector>

// class HashTable {
//  public:
//   HashTable();
//   bool Insert(const std::string& key, int value);
//   void InsertOrUpdate(const std::string& key, int value);
//   void Remove(const std::string& key);
//   int Find(const std::string& key) const;
//   size_t Size() const;  // размер вектора или количество ключей/значений

//  private:
//   struct Data {
//     Data(std::string k, int val);
//     std::string key;
//     int value;
//   };
//   int HashFunction(const std::string& key) const;
//   std::list<Data>::iterator Index(const std::string& key) const;

//   std::vector<std::list<Data>> data_;
// };
