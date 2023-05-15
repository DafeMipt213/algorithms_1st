#include <cstddef>
#include <stdexcept>  // Добавленный заголовочный файл
#include <string>

class TreeNode {
 public:
  std::string key;
  int value;
  TreeNode* left;
  TreeNode* right;

  TreeNode(const std::string& key, int value)
      : key(key), value(value), left(nullptr), right(nullptr) {}
};

class HashTable {
 public:
  HashTable();
  ~HashTable();

  bool Insert(const std::string& key, int value);
  void InsertOrUpdate(const std::string& key, int value);
  void Remove(const std::string& key);
  int Find(const std::string& key) const;
  size_t Size() const;

 private:
  TreeNode* root_;

  void DestroyTree(TreeNode* node);
  TreeNode* Insert(TreeNode* node, const std::string& key, int value);
  TreeNode* Find(TreeNode* node, const std::string& key) const;
};

HashTable::HashTable() : root_(nullptr) {}

HashTable::~HashTable() { DestroyTree(root_); }

void HashTable::DestroyTree(TreeNode* node) {
  if (node != nullptr) {
    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
  }
}

bool HashTable::Insert(const std::string& key, int value) {
  if (Find(root_, key) != nullptr) {
    return false;  // Key already exists
  }

  root_ = Insert(root_, key, value);
  return true;
}

TreeNode* HashTable::Insert(TreeNode* node, const std::string& key, int value) {
  if (node == nullptr) {
    return new TreeNode(key, value);
  }

  if (key < node->key) {
    node->left = Insert(node->left, key, value);
  } else if (key > node->key) {
    node->right = Insert(node->right, key, value);
  }

  return node;
}

void HashTable::InsertOrUpdate(const std::string& key, int value) {
  TreeNode* existingNode = Find(root_, key);
  if (existingNode != nullptr) {
    existingNode->value = value;
  } else {
    root_ = Insert(root_, key, value);
  }
}

void HashTable::Remove(const std::string& key) {
  // TODO: Implement removal logic
}

TreeNode* HashTable::Find(TreeNode* node, const std::string& key) const {
  if (node == nullptr || node->key == key) {
    return node;
  }

  if (key < node->key) {
    return Find(node->left, key);
  } else {
    return Find(node->right, key);
  }
}

int HashTable::Find(const std::string& key) const {
  TreeNode* node = Find(root_, key);
  if (node != nullptr) {
    return node->value;
  }
  throw std::out_of_range("Key not found");
}

size_t CountNodes(TreeNode* node) {
  if (node == nullptr) {
    return 0;
  }
  return 1 + CountNodes(node->left) + CountNodes(node->right);
}

size_t HashTable::Size() const { return CountNodes(root_); }
