// #include "hashtable.hpp"

// #include <algorithm>

// HashTable::HashTable() {}

// HashTable::Data::Data(std::string k, int val) : key{k}, value{val} {}

// std::list<HashTable::Data>::iterator HashTable::Index(
//     const std::string& key) const {
//   int index = HashFunction(key);
//   std::list<Data> elements = data_[index];

//   std::list<Data>::iterator iter =
//       std::find_if(elements.begin(), elements.end(),
//                    [key](const Data& elem) { return key == elem.key; });
//   return iter;
// }

// int HashTable::HashFunction(const std::string& key) const {
//   return std::hash<std::string>{}(key) % data_.size();
// }

// void HashTable::InsertOrUpdate(const std::string& key, int value) {
//   Data new_elem{key, value};
//   int index = HashFunction(key);
//   std::list<Data> elements = data_[index];

//   std::list<Data>::iterator iter = Index(key);

//   if (iter != elements.end())
//     data_[index].insert(iter, new_elem);
//   else
//     data_[index].push_back(new_elem);

//   return;
// }

// bool HashTable::Insert(const std::string& key, int value) {
//   Data new_elem{key, value};
//   int index = HashFunction(key);
//   std::list<Data> elements = data_[index];

//   std::list<Data>::iterator iter = Index(key);

//   if (iter != elements.end())
//     return false;
//   else {
//     data_[index].push_back(new_elem);
//     return true;
//   }
// }

// void HashTable::Remove(const std::string& key) {
//   int index = HashFunction(key);

//   auto value = this->Find(key);
// //   data_[index].remove(Data{key, value});
// }

// int HashTable::Find(const std::string& key) const {
//   int index = HashFunction(key);
//   std::list<Data> elements = data_[index];

//   std::list<Data>::iterator iter = Index(key);

//   if (iter != elements.end())
//     throw std::runtime_error("Element doesn't exist");
//   else
//     return iter->value;
// }

// size_t HashTable::Size() const {
//   size_t result = 0;
//   for (int i = 0; i < data_.size(); ++i) result += data_[i].size();
//   return result;
// }
