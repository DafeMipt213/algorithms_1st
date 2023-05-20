#pragma once

#include <cstdlib>
#include <map>
struct Node {
  int value, prior;
  Node* l_child = 0;
  Node* r_child = 0;
  Node(int _key) { value = _key, prior = rand(); }

  Node* merge(Node* l, Node* r);

  std::pair<Node*, Node*> split(Node* p, int x);
};
