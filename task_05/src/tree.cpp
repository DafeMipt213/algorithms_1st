#include "tree.hpp"

#include <stdexcept>

B_Tree::B_Tree() { root = nullptr; }

B_Tree::~B_Tree() {
  if (root != nullptr) DeleteNode(root);
}

void B_Tree::DeleteNode(Node *node) {
  if (node != nullptr) {
    for (int i = 0; i <= (2 * tree_parametr - 1); i++) {
      if (node->children[i] != nullptr)
        DeleteNode(node->children[i]);
      else {
        delete (node);
        break;
      }
    }
  }
}

void B_Tree::InsertToNode(int key, Node *node) {
  node->keys[node->count] = key;
  ++(node->count);
  Sort(node);
}

void B_Tree::Sort(Node *node) {
  int m;
  for (int i = 0; i < (2 * tree_parametr - 1); i++) {
    for (int j = i + 1; j <= (2 * tree_parametr - 1); j++) {
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

bool B_Tree::Insert(int key) {
  if (root == nullptr) {
    Node *new_кoot = new Node;
    new_кoot->keys[0] = key;
    for (int j = 1; j <= (2 * tree_parametr - 1); j++) new_кoot->keys[j] = 0;
    for (int i = 0; i <= (2 * tree_parametr); i++)
      new_кoot->children[i] = nullptr;
    new_кoot->count = 1;
    new_кoot->countSons = 0;
    new_кoot->leaf = true;
    new_кoot->parent = nullptr;
    root = new_кoot;
  } else {
    Node *ptr = root;
    while (
        ptr->leaf ==
        false) {  //выбор ребенка до тех пор, пока узел не будет являться листом
      for (int i = 0; i <= (2 * tree_parametr - 1);
           i++) {  //перебираем все ключи
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
    InsertToNode(key, ptr);

    while (ptr->count == 2 * tree_parametr) {
      if (ptr == root) {
        Restruct(ptr);
        break;
      } else {
        Restruct(ptr);
        ptr = ptr->parent;
      }
    }
  }
}

void B_Tree::Restruct(Node *node) {
  if (node->count < (2 * tree_parametr - 1)) return;

  //первый сын
  Node *child1 = new Node;
  int j;
  for (j = 0; j <= tree_parametr - 2; j++) child1->keys[j] = node->keys[j];
  for (j = tree_parametr - 1; j <= (2 * tree_parametr - 1); j++)
    child1->keys[j] = 0;
  child1->count = tree_parametr - 1;  //количество ключей в узле
  if (node->countSons != 0) {
    for (int i = 0; i <= (tree_parametr - 1); i++) {
      child1->children[i] = node->children[i];
      child1->children[i]->parent = child1;
    }
    for (int i = tree_parametr; i <= (2 * tree_parametr); i++)
      child1->children[i] = nullptr;
    child1->leaf = false;
    child1->countSons = tree_parametr - 1;  //количество сыновей
  } else {
    child1->leaf = true;
    child1->countSons = 0;
    for (int i = 0; i <= (2 * tree_parametr); i++)
      child1->children[i] = nullptr;
  }

  //второй сын
  Node *child2 = new Node;
  for (int j = 0; j <= (tree_parametr - 1); j++)
    child2->keys[j] = node->keys[j + tree_parametr];
  for (j = tree_parametr; j <= (2 * tree_parametr - 1); j++)
    child2->keys[j] = 0;
  child2->count = tree_parametr;  //количество ключей в узле
  if (node->countSons != 0) {
    for (int i = 0; i <= (tree_parametr); i++) {
      child2->children[i] = node->children[i + tree_parametr];
      child2->children[i]->parent = child2;
    }
    for (int i = tree_parametr + 1; i <= (2 * tree_parametr); i++)
      child2->children[i] = nullptr;
    child2->leaf = false;
    child2->countSons = tree_parametr;  //количество сыновей
  } else {
    child2->leaf = true;
    child2->countSons = 0;
    for (int i = 0; i <= (2 * tree_parametr); i++)
      child2->children[i] = nullptr;
  }

  //родитель
  if (node->parent == nullptr) {  //если родителя нет, то это корень
    node->keys[0] = node->keys[tree_parametr - 1];
    for (int j = 1; j <= (2 * tree_parametr - 1); j++) node->keys[j] = 0;
    node->children[0] = child1;
    node->children[1] = child2;
    for (int i = 2; i <= (2 * tree_parametr); i++) node->children[i] = nullptr;
    node->parent = nullptr;
    node->leaf = false;
    node->count = 1;
    node->countSons = 2;
    child1->parent = node;
    child2->parent = node;
  } else {
    InsertToNode(node->keys[tree_parametr - 1], node->parent);
    for (int i = 0; i <= (2 * tree_parametr); i++) {
      if (node->parent->children[i] == node)
        node->parent->children[i] = nullptr;
    }
    for (int i = 0; i <= (2 * tree_parametr); i++) {
      if (node->parent->children[i] == nullptr) {
        for (int j = (2 * tree_parametr); j > (i + 1); j--)
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

bool B_Tree::Find(int key) { return SearchKey(key, root); }

bool B_Tree::SearchKey(int key, Node *node) {
  if (node != nullptr) {
    if (node->leaf == false) {
      int i;
      for (i = 0; i <= (2 * tree_parametr - 1); i++) {
        if (node->keys[i] != 0) {
          if (key == node->keys[i]) return true;
          if ((key < node->keys[i])) {
            return SearchKey(key, node->children[i]);
            break;
          }
        } else
          break;
      }
      return SearchKey(key, node->children[i]);
    } else {
      for (int j = 0; j <= (2 * tree_parametr - 1); j++)
        if (key == node->keys[j]) return true;
      return false;
    }
  } else
    return false;
}

void B_Tree::InsertOrUpdate(int key) {}