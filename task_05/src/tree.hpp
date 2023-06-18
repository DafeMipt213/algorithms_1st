#pragma once

#include <cstdlib>
#include <map>
#include <random>

struct Treap {
  static std::minstd_rand generate;
  struct Node {
    int key, priority;

    Node *l = nullptr, *r = nullptr;
    Node(int key) : key(key), priority(generate()) {}
  } *root = nullptr;

  Node *merge(Node *a, Node *b) {
    if (!a or !b) return a ? a : b;
    if (a->priority > b->priority) {
      a->r = merge(a->r, b);
      return a;
    } else {
      b->l = merge(a, b->l);
      return b;
    }
  }

  void split(Node *n, int key, Node *&a, Node *&b) {
    if (!n) {
      a = b = nullptr;
      return;
    }
    if (n->key < key) {
      split(n->r, key, n->r, b);
      a = n;
    } else {
      split(n->l, key, a, n->l);
      b = n;
    }
  }

 public:
  inline bool find(int key) {
    Node *less, *equal, *greater;
    split(root, key, less, greater);
    split(greater, key + 1, equal, greater);
    bool result = equal;
    root = merge(merge(less, equal), greater);
    return result;
  }

  inline bool insert(int key) {
    if (!find(key)) {
      Node *less, *greater;
      split(root, key, less, greater);
      root = merge(merge(less, new Node(key)), greater);
      return true;
    } else
      return false;
  }

  inline void erase(int key) {
    Node *less, *equal, *greater;
    split(root, key, less, greater);
    split(greater, key + 1, equal, greater);
    equal = merge(equal->l, equal->r);
    root = merge(less, greater);
  }
};

inline std::minstd_rand Treap::generate;