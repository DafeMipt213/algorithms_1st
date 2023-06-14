#include "hashtable.hpp"

HashTable::HashTable() {
    data_.resize(kTableSize);
}

bool HashTable::Insert(const std::string& key, int value) {
    size_t index = HashFunction(key);
    std::vector<KeyValue>& bucket = data_[index];

    for (const auto& entry : bucket) {
        if (entry.key == key) {
            return false; 
        }
    }

    bucket.emplace_back(key, value);
    return true;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
    size_t index = HashFunction(key);
    std::vector<KeyValue>& bucket = data_[index];

    for (auto& entry : bucket) {
        if (entry.key == key) {
            entry.value = value;
            return;
        }
    }

 
    bucket.emplace_back(key, value);
}

void HashTable::Remove(const std::string& key) {
    size_t index = HashFunction(key);
    std::vector<KeyValue>& bucket = data_[index];


    auto it = std::find_if(bucket.begin(), bucket.end(), [&key](const KeyValue& entry) {
        return entry.key == key;
    });

    if (it != bucket.end()) {
        bucket.erase(it);
    }
}

int HashTable::Find(const std::string& key) const {
    size_t index = HashFunction(key);
    const std::vector<KeyValue>& bucket = data_[index];

    for (const auto& entry : bucket) {
        if (entry.key == key) {
            return entry.value;
        }
    }

    return 0;
}

size_t HashTable::Size() const {
    size_t count = 0;
    for (const auto& bucket : data_) {
        count += bucket.size();
    }
    return count;
}

size_t HashTable::HashFunction(const std::string& key) const {
    size_t hash = 0;
    for (char ch : key) {
        hash = (hash * 31 + ch) % kTableSize;
    }
    return hash;
}
