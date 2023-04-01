// #include "tree.hpp"

// #include <exception>
// #include <stdexcept>

// Tree::Tree() {}

// bool Tree::Insert(int key, int value) {
//   if (this->Find(key)) return false;

//   return true;
// }

// void Tree::InsertOrUpdate(int key, int value) {}

// int Tree::Find(int key) const {
//   if (root == nullptr) throw std::out_of_range("Tree is empty");
//   if (root->key == key) return root->data;
//   if (root->left_child == nullptr and root->right_child == nullptr)
//     throw std::runtime_error("Element hasn't been found");
//   else if (key < root->key)
//     return this->Find(key, root->left_child);
//   else
//     return this->Find(key, root->right_child);
// }
