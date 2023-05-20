#pragma once

template <typename T>
struct Node {
 private:
  Node<T> *parent = nullptr;
  Node<T> *left = nullptr;
  Node<T> *right = nullptr;
  T key = T();
  bool color = false; //false = black, true = red

 public:
  
  Node *GetBack() { return this->back; }
  Node *GetNext() { return this->next; }
  T GetValue() { return this->key; }
};
template <typename T>
class Tree {
 public:
  Tree();
  bool Insert(T key);
  void InsertOrUpdate(T key);
  int Find(T key) const;
};
