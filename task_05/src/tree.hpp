#pragma once
#include <iostream>
#include <memory>
#include <vector>

struct Node {
  Node* parent = nullptr;
  Node* left_child = nullptr;
  Node* right_child = nullptr;
  ~Node();
  int data;
  int key;
  void operator=(const Node& other);
};

class Tree {

 public:
  void LeftZig(Node*);
  void RightZig(Node*);
  void LeftZigZig(Node*);
  void RightZigZig(Node*);
  void LeftZigZag(Node*);
  void RightZigZag(Node*);
  void Splay(Node*);
  Node* root = nullptr;
  Tree();
  ~Tree();
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key);
  void Remove(int key);
  void RemoveSplay(int key);
};