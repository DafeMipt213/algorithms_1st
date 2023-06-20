#include "tree.hpp"

Treap *Tree::merge(Treap *t1, Treap *t2) {
  if (t1 == nullptr) {
    return t2;
  }
  if (t2 == nullptr) {
    return t1;
  }
  if (t1->y > t2->y) {
    t1->Right = merge(t1->Right, t2);
    upd(t1);
    return t1;
  } else {
    t2->Left = merge(t1, t2->Left);
    upd(t2);
    return t2;
  }
}

void Tree::split(Treap *t, int x, Treap *&t1, Treap *&t2) {
  if (t == nullptr) {
    t1 = t2 = nullptr;
    return;
  }
  if (t->x < x) {
    split(t->Right, x, t->Right, t2);
    t1 = t;
  } else {
    split(t->Left, x, t1, t->Left);
    t2 = t;
  }
  upd(t);
}

size_t Tree::get_size(Treap *t) {
  if (t == nullptr) {
    return 0;
  }
  return t->size;
}

void Tree::upd(Treap *t) {
  if (t != nullptr) {
    t->size = 1 + get_size(t->Left) + get_size(t->Right);
  }
}

void Tree::add(Treap *&t, int x, int y) {
  Treap *t1;
  Treap *t2;
  split(t, x, t1, t2);
  Treap *n_tree = new Treap(x, rand());
  t = merge(merge(t1, n_tree), t2);
}

void Tree::remove(Treap *&t, int x) {
  Treap *t1, *t2, *t3, *t4;
  split(t, x, t1, t2);
  split(t2, x + 1, t3, t4);
  t = merge(t1, t4);
  delete t3;
}

int Tree::get_elem(Treap *t, int k) {
  if (k < get_size(t->Left)) {
    return get_elem(t->Left, k);
  } else if (k == get_size(t->Left)) {
    return t->x;
  } else {
    return get_elem(t->Right, k - get_size(t->Left) - 1);
  }
}
