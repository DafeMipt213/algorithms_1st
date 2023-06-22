#pragma once

#include <cstddef>
#include <cstdlib>

struct Treap {
  int x;
  int y;
  size_t size;
  Treap *Left;
  Treap *Right;
  Treap(int x, int y, Treap *Left = nullptr, Treap *Right = nullptr)
      : x(x), y(y), Left(Left), Right(Right) {}
};

struct Tree {
  Treap *merge(Treap *t1, Treap *t2);
  void split(Treap *t, int x, Treap *&t1, Treap *&t2);
  size_t get_size(Treap *t);
  void upd(Treap *t);
  void add(Treap *&t, int x, int y = rand());
  void remove(Treap *&t, int x);
  int get_elem(Treap *t, int k);
};
