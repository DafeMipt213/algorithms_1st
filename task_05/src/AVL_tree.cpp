#include "AVL_tree.hpp"

int Node::factor() {
  return (left != nullptr ? left->height : 0) -
         (right != nullptr ? right->height : 0);
}

void Node::update_height() {
  count = (left != nullptr ? left->count : 0) +
          (right != nullptr ? right->count : 0) + 1;

  height = std::max(left != nullptr ? left->height : 0,
                    right != nullptr ? right->height : 0) +
           1;
}

Node* Node::rotate_left() {
  Node* R = right;
  right = right->left;
  R->left = this;
  this->update_height();
  R->update_height();
  return R;
}

Node* Node::rotate_right() {
  Node* L = left;
  left = left->right;
  L->right = this;
  this->update_height();
  L->update_height();
  return L;
}

AVL_tree::AVL_tree() {
  root = nullptr;
  size = 0;
}

AVL_tree::~AVL_tree() { delete_tree(); }

void AVL_tree::delete_tree() {
  std::vector<Node*> stack;
  if (root != nullptr) {
    stack.push_back(root);
  }
  while (stack.size() != 0) {
    Node* node = stack.back();
    stack.pop_back();
    if (node->left != nullptr) {
      stack.push_back(node->left);
    }
    if (node->right != nullptr) {
      stack.push_back(node->right);
    }
    size--;
    delete node;
  }
  root = nullptr;
}

void AVL_tree::Insert(int k) {
  Node** ind = &root;
  std::vector<Node**> path;
  while (ind != nullptr) {
    path.push_back(ind);
    ind = (*ind)->key > k ? &((*ind)->left) : &((*ind)->right);
  }
  *ind = new Node(k);
  path.push_back(ind);
  balanced(path);
  ++size;
}

void AVL_tree::balanced(std::vector<Node**> path) {
  std::reverse(path.begin(), path.end());

  for (auto indirect : path) {
    (*indirect)->update_height();

    if ((*indirect)->factor() >= 2 and (*indirect)->left->factor() >= 0)
      *indirect = (*indirect)->rotate_right();

    else if ((*indirect)->factor() >= 2) {
      (*indirect)->left = (*indirect)->left->rotate_left();
      *indirect = (*indirect)->rotate_right();
    }

    else if ((*indirect)->factor() <= -2 and (*indirect)->right->factor() <= 0)
      *indirect = (*indirect)->rotate_left();

    else if ((*indirect)->factor() <= -2) {
      (*indirect)->right = ((*indirect)->right)->rotate_right();
      *indirect = (*indirect)->rotate_left();
    }
  }
}

int AVL_tree::Find(int k) const {
  Node* direct = root;
  int idx = 0;

  while (direct != nullptr and direct->key != k) {
    if (direct->key > k)
      direct = direct->left;
    else {
      idx += (direct->left ? direct->left->count : 0) + 1;
      direct = direct->right;
    }
  }
  if (direct == nullptr)
    return -1;

  else
    return idx + (direct->left ? direct->left->count : 0);
}
