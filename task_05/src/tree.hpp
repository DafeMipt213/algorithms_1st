#pragma once

class Tree {
 public:
  Tree();
  bool Insert(int key, int value);
  // если такой эл есть - возвращаем false, если нет - возвращаем true  и вставляем
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

private:
  struct Node {
    Node *parent = nullptr;
    Node *left_child = nullptr;
    Node *right_child = nullptr;

    int key;
    int value;

    void change_node(int new_key, int new_value) {
      key = new_key;
      value = new_value;
    }
  };

  Node *root = nullptr;


};
