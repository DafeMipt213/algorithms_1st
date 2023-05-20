#include "tree.hpp"

Node* Node::merge(Node* l, Node* r) {
  if (!l) return r;
  if (!r) return l;
  if (l->prior > r->prior) {
    l->r_child = merge(l->r_child, r);
    return l;
  } else {
    r->l_child = merge(l, r->l_child);
    return r;
  }
}

std::pair<Node*, Node*> split(Node* p, int x) {
  if (!p) return {0, 0};
  if (p->value <= x) {
    std::pair<Node*, Node*> q = split(p->r_child, x);
    p->r_child = q.first;
    return {p, q.second};
  } else {
    std::pair<Node*, Node*> q = split(p->l_child, x);
    p->l_child = q.second;
    return {q.first, p};
  }
}