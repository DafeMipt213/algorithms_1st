#pragma once

#include <string>
#include <vector>

struct KeyValue {
    std::string key;
    int value;

    KeyValue(const std::string& k, int v) : key(k), value(v) {}
};

class HashTable {
public:
    HashTable();
    bool Insert(const std::string& key, int value);
    void InsertOrUpdate(const std::string& key, int value);
    void Remove(const std::string& key);
    int Find(const std::string& key) const;
    size_t Size() const;

private:
    static const size_t kTableSize = 100; 
    std::vector<std::vector<KeyValue>> data_; 

    size_t HashFunction(const std::string& key) const;
};
