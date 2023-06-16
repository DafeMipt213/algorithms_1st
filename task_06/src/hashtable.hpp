#pragma once

#include <string>
#include <vector>

class HashTable {
 public:
  HashTable();
  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string& key);
  int Find(const std::string& key) const;
  size_t Size() const;

 private:
  int Hash(const std::string& key) const;
  size_t element_count = 0;
  void Rehash();

  class Data {
   public:
    class KeyValue {
     public:
      KeyValue(std::string key, int value) : key{key}, value{value} {}
      std::string GetKey() const { return key; }
      int GetValue() const { return value; }
      void SetValue(int new_value) { value = new_value; }

     private:
      std::string key;
      int value;
    };

    bool Push(KeyValue);
    int Update(KeyValue);
    int GetValue(const std::string& key) const;
    int Remove(const std::string& key);
    size_t Size() const { return data_.size(); }
    KeyValue GetKeyValue(size_t index);
    void Pop(size_t index);

   private:
    bool IsKeyContains(const KeyValue& pair) const;
    std::vector<KeyValue> data_;
  };

  std::vector<Data> data_;
};
