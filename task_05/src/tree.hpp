#pragma once

#include <cstdlib>
#include <map>
#include <random>

struct Treap {
  static std::minstd_rand generate;
  struct Node {
    int key;
    int priority;

    Node *left = nullptr, *r = nullptr;
    Node(int key) : key(key), priority(generate()) {}
  } *root = nullptr;

  Node *Merge(Node *a, Node *b) {
    if (!a or !b) return a ? a : b;
    if (a->priority > b->priority) {
      a->r = Merge(a->r, b);
      return a;
    } else {
      b->left = Merge(a, b->left);
      return b;
    }
  }

  void Split(Node *n, int key, Node *&a, Node *&b) {
    if (!n) {
      a = b = nullptr;
      return;
    }
    if (n->key < key) {
      Split(n->r, key, n->r, b);
      a = n;
    } else {
      Split(n->left, key, a, n->left);
      b = n;
    }
  }

 public:
  inline bool Find(int key) {
    Node *less, *equal, *greater;
    Split(root, key, less, greater);
    Split(greater, key + 1, equal, greater);
    bool result = equal;
    root = Merge(Merge(less, equal), greater);
    return result;
  }

  inline bool Insert(int key) {
    if (!Find(key)) {
      Node *less, *greater;
      Split(root, key, less, greater);
      root = Merge(Merge(less, new Node(key)), greater);
      return true;
    } else
      return false;
  }

  inline void Erase(int key) {
    Node *less, *equal, *greater;
    Split(root, key, less, greater);
    Split(greater, key + 1, equal, greater);
    equal = Merge(equal->left, equal->r);
    root = Merge(less, greater);
  }
};

inline std::minstd_rand Treap::generate;