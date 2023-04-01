#pragma once
#include <iostream>
#include <memory>
#include <vector>
class Tree {
 private:
  struct Node {
    Node* parent = nullptr;
    Node* left_child = nullptr;
    Node* right_child = nullptr;
    int data;
    int key;
    bool visited = false;
    void operator=(Node other) {
      parent = other.parent;
      left_child = other.left_child;
      right_child = other.right_child;
      data = other.data;
      key = other.key;
    }
  };

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
  bool Insert(int key, int value);
  void InsertOrUpdate(int key, int value);
  int Find(int key);
  void Remove(int key);
};

static std::string ch_hor = "\u2500" /*─*/, ch_ver = "\u2502" /*│*/,
                   ch_ddia = "\u250C" /*┌*/, ch_rddia = "\u2510" /*┐*/,
                   ch_udia = "\u2514" /*└*/, ch_ver_hor = "\u251C\u2500" /*├─*/,
                   ch_udia_hor = "\u2514\u2500" /*└─*/,
                   ch_ddia_hor = "\u250C\u2500" /*┌─*/,
                   ch_ver_spa = "\u2502 " /*│ */;

void Show(
    Tree* node, bool high = true,
    std::vector<std::string> const& lpref = std::vector<std::string>(),
    std::vector<std::string> const& cpref = std::vector<std::string>(),
    std::vector<std::string> const& rpref = std::vector<std::string>(),
    bool root = true, bool left = true,
    std::shared_ptr<std::vector<std::vector<std::string>>> lines = nullptr);

void ShowTree(Tree* node);