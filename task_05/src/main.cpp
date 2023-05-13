#include <iostream>
#include <vector>

#include "tree.hpp"

int main() {
  Tree a;
  a.insert(13, 12);
  a.insert(14, 14);
  a.insert(15, 15);
  a.insert(12, 15);
  std::cout << a.root->left_child->left_child->Key;
  a.remove(13);
  std::cout << a.root->left_child->Key;
  a.remove(14);
  std::cout << a.root->Key;
  // std::cout << a.root->right_child->Key;
  // std::cout << a.root->left_child->Key;
  return 0;
}
