// #include "tree.hpp"

// #include <exception>
// #include <stdexcept>
// #include <algorithm>

// Tree::Tree() {}

// Tree::Node::Node() 
// {
//     keys.reserve(2 * t);
//     values.reserve(2 * t);
//     children.reserve(2 * t + 1);
//     for (size_t i = 0; i < children.size(); ++i)
//         children[i] = nullptr;
// }

// Tree::~Tree(){
//     if (root != nullptr)
//         NodeDeletion(root);
// }

// void Tree::NodeDeletion(Node* node)
// {
//     if (node != nullptr){
//         for (int i = 0; i <= (2 * t - 1); i++){
//             if (node->children[i] != nullptr){
//                 NodeDeletion(node->children[i]);
//             }
//             else{
//                 delete(node);
//                 break;
//             }
//         }
//     }
// }

// void Tree::SimpleInsert(int key, int value, Node* node)
// {
//     for (size_t i = 0; i < node->keys_count; ++i)
//         if (key <= node->keys[i]){
//             node->keys.insert(node->keys.begin() + i, key);
//             node->values.insert(node->values.begin() + i, value);
//             return;
//         }
// }

// bool Tree::Insert(int key, int value) {
//   if (this->Find(key)) return false;
  
//   if (root == nullptr){
//     root = new Node;
//     root->values[0] = value;
//     root->keys[0] = key;
//     return true;
//   }
  

//   return true;
// }




// // void Tree::InsertOrUpdate(int key, int value) {}

// // int Tree::Find(int key) const {
// //   if (root == nullptr) throw std::out_of_range("Tree is empty");
// //   if (root->key == key) return root->data;
// //   if (root->left_child == nullptr and root->right_child == nullptr)
// //     throw std::runtime_error("Element hasn't been found");
// //   else if (key < root->key)
// //     return this->Find(key, root->left_child);
// //   else
// //     return this->Find(key, root->right_child);
// // }
