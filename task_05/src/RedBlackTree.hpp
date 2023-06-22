#pragma once
enum COLORS { RED, BLACK };

template <typename T>
struct Node {
  Node(T key, COLORS colors, Node* parent = nullptr, Node* left = nullptr,
       Node* right = nullptr)
      : key(key), colors(colors), parent(parent), left(left), right(right) {}
  Node* parent = nullptr;
  Node* left = nullptr;
  Node* right = nullptr;
  enum COLORS colors;
  T key;
};

template <typename T>
class Red_Black_Tree {
 public:
  Red_Black_Tree();
  ~Red_Black_Tree();
  void insert(T key);
  void remove(T key);
  Node<T>* find(T key) const;

 private:
  void check_remove(Node<T>* node, Node<T>* parent);
  Node<T>* find(Node<T>* n, T key) const;
  void delete_tree(Node<T>* n);
  void check_insert(Node<T>* n);
  void left_rotate(Node<T>* n);
  void right_rotate(Node<T>* n);
  Node<T>* root;
};