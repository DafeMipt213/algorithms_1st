#pragma once


class Tree {
/*
private:
  enum class Color {Red, Black};
  struct Node{
        Node* parent = nullptr;
        Node* left_child = nullptr;
        Node* right_child = nullptr;
        int Key;
        // 0 - red, 
        Color c = Color::Red;
  };
*/
public:
/*
  Node* root = nullptr;
*/
  Tree();

  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key) const;

};
