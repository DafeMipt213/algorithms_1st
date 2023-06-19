#include "tree.hpp"

#include <stdexcept>

Tree::Tree() { root = nullptr; }

Tree::~Tree() {
  if (root != nullptr) deletenode(root);
}

void Tree::deletenode(Node *node) {
  if (node != nullptr) {
    for (int i = 0; i <= (2 * t - 1); i++) {
      if (node->children[i] != nullptr)
        deletenode(node->children[i]);
      else {
        delete (node);
        break;
      }
    }
  }
}

void Tree::insert_to_node(int key, Node *node) {
  node->keys[node->count] = key;
  node->count = node->count + 1;
  sort(node);
}

void Tree::sort(Node *node) {
  int m;
  for (int i = 0; i < (2 * t - 1); i++) {
    for (int j = i + 1; j <= (2 * t - 1); j++) {
      if ((node->keys[i] != 0) && (node->keys[j] != 0)) {
        if ((node->keys[i]) > (node->keys[j])) {
          m = node->keys[i];
          node->keys[i] = node->keys[j];
          node->keys[j] = m;
        }
      } else
        break;
    }
  }
}

bool Tree::Insert(int key) {
  if (root == nullptr) {
    Node *newRoot = new Node;
    newRoot->keys[0] = key;
    for (int j = 1; j <= (2 * t - 1); j++) newRoot->keys[j] = 0;
    for (int i = 0; i <= (2 * t); i++) newRoot->children[i] = nullptr;
    newRoot->count = 1;
    newRoot->countSons = 0;
    newRoot->leaf = true;
    newRoot->parent = nullptr;
    root = newRoot;
  } else {
    Node *ptr = root;
    while (
        ptr->leaf ==
        false) {  //выбор ребенка до тех пор, пока узел не будет являться листом
      for (int i = 0; i <= (2 * t - 1); i++) {  //перебираем все ключи
        if (ptr->keys[i] != 0) {
          if (key < ptr->keys[i]) {
            ptr = ptr->children[i];
            break;
          }
          if ((ptr->keys[i + 1] == 0) && (key > ptr->keys[i])) {
            ptr = ptr->children[i + 1];  //перенаправляем к самому последнему
                                         //ребенку, если цикл не "сломался"
            break;
          }
        } else
          break;
      }
    }
    insert_to_node(key, ptr);

    while (ptr->count == 2 * t) {
      if (ptr == root) {
        restruct(ptr);
        break;
      } else {
        restruct(ptr);
        ptr = ptr->parent;
      }
    }
  }
}

void Tree::restruct(Node *node) {
  if (node->count < (2 * t - 1)) return;

  //первый сын
  Node *child1 = new Node;
  int j;
  for (j = 0; j <= t - 2; j++) child1->keys[j] = node->keys[j];
  for (j = t - 1; j <= (2 * t - 1); j++) child1->keys[j] = 0;
  child1->count = t - 1;  //количество ключей в узле
  if (node->countSons != 0) {
    for (int i = 0; i <= (t - 1); i++) {
      child1->children[i] = node->children[i];
      child1->children[i]->parent = child1;
    }
    for (int i = t; i <= (2 * t); i++) child1->children[i] = nullptr;
    child1->leaf = false;
    child1->countSons = t - 1;  //количество сыновей
  } else {
    child1->leaf = true;
    child1->countSons = 0;
    for (int i = 0; i <= (2 * t); i++) child1->children[i] = nullptr;
  }

  //второй сын
  Node *child2 = new Node;
  for (int j = 0; j <= (t - 1); j++) child2->keys[j] = node->keys[j + t];
  for (j = t; j <= (2 * t - 1); j++) child2->keys[j] = 0;
  child2->count = t;  //количество ключей в узле
  if (node->countSons != 0) {
    for (int i = 0; i <= (t); i++) {
      child2->children[i] = node->children[i + t];
      child2->children[i]->parent = child2;
    }
    for (int i = t + 1; i <= (2 * t); i++) child2->children[i] = nullptr;
    child2->leaf = false;
    child2->countSons = t;  //количество сыновей
  } else {
    child2->leaf = true;
    child2->countSons = 0;
    for (int i = 0; i <= (2 * t); i++) child2->children[i] = nullptr;
  }

  //родитель
  if (node->parent == nullptr) {  //если родителя нет, то это корень
    node->keys[0] = node->keys[t - 1];
    for (int j = 1; j <= (2 * t - 1); j++) node->keys[j] = 0;
    node->children[0] = child1;
    node->children[1] = child2;
    for (int i = 2; i <= (2 * t); i++) node->children[i] = nullptr;
    node->parent = nullptr;
    node->leaf = false;
    node->count = 1;
    node->countSons = 2;
    child1->parent = node;
    child2->parent = node;
  } else {
    insert_to_node(node->keys[t - 1], node->parent);
    for (int i = 0; i <= (2 * t); i++) {
      if (node->parent->children[i] == node)
        node->parent->children[i] = nullptr;
    }
    for (int i = 0; i <= (2 * t); i++) {
      if (node->parent->children[i] == nullptr) {
        for (int j = (2 * t); j > (i + 1); j--)
          node->parent->children[j] = node->parent->children[j - 1];
        node->parent->children[i + 1] = child2;
        node->parent->children[i] = child1;
        break;
      }
    }
    child1->parent = node->parent;
    child2->parent = node->parent;
    node->parent->leaf = false;
    delete node;
  }
}

bool Tree::Find(int key) { return searchKey(key, root); }

bool Tree::searchKey(int key, Node *node) {
  if (node != nullptr) {
    if (node->leaf == false) {
      int i;
      for (i = 0; i <= (2 * t - 1); i++) {
        if (node->keys[i] != 0) {
          if (key == node->keys[i]) return true;
          if ((key < node->keys[i])) {
            return searchKey(key, node->children[i]);
            break;
          }
        } else
          break;
      }
      return searchKey(key, node->children[i]);
    } else {
      for (int j = 0; j <= (2 * t - 1); j++)
        if (key == node->keys[j]) return true;
      return false;
    }
  } else
    return false;
}

void Tree::InsertOrUpdate(int key) {}