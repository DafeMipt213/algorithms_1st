#include "tree.hpp"

#include <stdexcept>

Tree::Tree() {}

bool Tree::Insert(int key, int value) {
  if (root == nullptr) {
    Node* tmpnode = new Node;
    tmpnode->key = key;
    tmpnode->data = value;
    root = tmpnode;
    return true;
  } else {
    Node* tmpnode = new Node;
    tmpnode = root;
    while (true) {
      if (key > tmpnode->key) {
        if (tmpnode->right_child == nullptr) {
          Node* temp = new Node;
          temp->parent = tmpnode;
          temp->left_child = nullptr;
          temp->right_child = nullptr;
          temp->key = key;
          temp->data = value;
          tmpnode->right_child = temp;
          this->Splay(tmpnode->right_child);
          return true;
        } else {
          tmpnode = tmpnode->right_child;
        }
      } else if (key == tmpnode->key) {
        return false;
      } else {
        if (tmpnode->left_child == nullptr) {
          Node* temp = new Node;
          temp->parent = tmpnode;
          temp->left_child = nullptr;
          temp->right_child = nullptr;
          temp->key = key;
          temp->data = value;
          tmpnode->left_child = temp;
          this->Splay(tmpnode->left_child);
          return true;
        } else {
          tmpnode = tmpnode->left_child;
        }
      }
    }
  }
}

void Tree::InsertOrUpdate(int key, int value) {
  if (root == nullptr) {
    Node* tmpnode = new Node;
    tmpnode->key = key;
    tmpnode->data = value;
    root = tmpnode;
    return;
  } else {
    Node* tmpnode = new Node;
    tmpnode = root;
    while (true) {
      if (key > tmpnode->key) {
        if (tmpnode->right_child == nullptr) {
          Node* temp = new Node;
          temp->parent = tmpnode;
          temp->left_child = nullptr;
          temp->right_child = nullptr;
          temp->key = key;
          temp->data = value;
          tmpnode->right_child = temp;
          this->Splay(tmpnode->right_child);
          return;
        } else {
          tmpnode = tmpnode->right_child;
        }
      } else if (key == tmpnode->key) {
        tmpnode->data = value;
        this->Splay(tmpnode);
        return;
      } else {
        if (tmpnode->left_child == nullptr) {
          Node* temp = new Node;
          temp->parent = tmpnode;
          temp->left_child = nullptr;
          temp->right_child = nullptr;
          temp->key = key;
          temp->data = value;
          tmpnode->left_child = temp;
          this->Splay(tmpnode->left_child);
          return;
        } else {
          tmpnode = tmpnode->left_child;
        }
      }
    }
  }
}

int Tree::Find(int key) {
  if (root == nullptr) {
    throw std::range_error("Tree is empty");
  } else {
    Node* tmpnode = new Node;
    tmpnode->parent = nullptr;
    tmpnode->left_child = root->left_child;
    tmpnode->right_child = root->right_child;
    tmpnode->key = root->key;
    tmpnode->data = root->data;
    while (true) {
      if (key > tmpnode->key) {
        if (root->right_child == nullptr) {
          throw std::range_error("No element with such key in a tree");
        } else {
          tmpnode = tmpnode->right_child;
        }
      } else if (key == tmpnode->key) {
        this->Splay(tmpnode);
        return tmpnode->data;
      } else {
        if (root->left_child == nullptr) {
          throw std::range_error("Tree is empty");
        } else {
          tmpnode = tmpnode->left_child;
        }
      }
    }
  }
}

void Tree::Remove(int key) {
  if (root == nullptr) {
    throw std::range_error("Tree is empty");
  }
  if (key == root->key) {
    if (root->left_child == nullptr and root->right_child == nullptr) {
      root = nullptr;
    } else if (root->left_child != nullptr and root->right_child == nullptr) {
      root = root->left_child;
    } else if (root->left_child == nullptr and root->right_child != nullptr) {
      root = root->right_child;
    } else {
      Node* best_child = new Node;
      best_child = root->right_child;
      while (best_child->left_child != nullptr) {
        best_child = best_child->left_child;
      }
      root->key = best_child->key;
      root->data = best_child->data;
      if (best_child->parent->left_child->key == best_child->key) {
        best_child->parent->left_child = best_child->right_child;
      } else {
        best_child->parent->right_child = best_child->right_child;
      }
      best_child = nullptr;
    }
    return;
  }
  Node* tmpnode = new Node;
  tmpnode->parent = nullptr;
  tmpnode->left_child = root->left_child;
  tmpnode->right_child = root->right_child;
  tmpnode->key = root->key;
  tmpnode->data = root->data;
  while (true) {
    if (key > tmpnode->key) {
      if (root->right_child == nullptr) {
        throw std::range_error("No element with such key in a tree");
      } else {
        tmpnode = tmpnode->right_child;
      }
    } else if (key == tmpnode->key) {
      if (tmpnode->right_child == nullptr && tmpnode->left_child == nullptr) {
        Node* father = tmpnode->parent;
        if (father->left_child != nullptr and father->left_child->key == key)
          father->left_child = nullptr;
        else
          father->right_child = nullptr;
      } else if (tmpnode->right_child == nullptr &&
                 tmpnode->left_child != nullptr) {
        Node* father = tmpnode->parent;
        if (father->left_child->key == key)
          father->left_child = tmpnode->left_child;
        else
          father->right_child = tmpnode->left_child;
        tmpnode = tmpnode->left_child;
      } else if (tmpnode->right_child != nullptr &&
                 tmpnode->left_child == nullptr) {
        Node* father = tmpnode->parent;
        if (father->left_child != nullptr and father->left_child->key == key)
          father->left_child = tmpnode->right_child;
        else
          father->right_child = tmpnode->right_child;
        tmpnode = tmpnode->right_child;
      } else {
        Node* best_child = new Node;
        best_child = tmpnode->right_child;
        while (best_child->left_child != nullptr) {
          best_child = best_child->left_child;
        }
        tmpnode->key = best_child->key;
        tmpnode->data = best_child->data;
        Node* father = best_child->parent;
        if (father->left_child->key == key)
          father->left_child = best_child->right_child;
        else
          father->right_child = best_child->right_child;
        best_child = best_child->right_child;
      }
      return;
    } else {
      if (root->left_child == nullptr) {
        throw std::range_error("Tree is empty");
      } else {
        tmpnode = tmpnode->left_child;
      }
    }
  }
}
void Show(Tree* node, bool high, std::vector<std::string> const& lpref,
          std::vector<std::string> const& cpref,
          std::vector<std::string> const& rpref, bool root, bool left,
          std::shared_ptr<std::vector<std::vector<std::string>>> lines) {
  if (!node) return;
  typedef std::vector<std::string> VS;
  auto VSCat = [](VS const& a, VS const& b) {
    auto r = a;
    r.insert(r.end(), b.begin(), b.end());
    return r;
  };
  if (root) lines = std::make_shared<std::vector<VS>>();
  if (node->root->left_child) {
    Tree* tmptree = new Tree;
    tmptree->root = node->root->left_child;
    Show(tmptree, high, VSCat(lpref, high ? VS({" ", " "}) : VS({" "})),
         VSCat(lpref, high ? VS({ch_ddia, ch_ver}) : VS({ch_ddia})),
         VSCat(lpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), false, true,
         lines);
  }
  auto sval = std::to_string(node->root->key);
  size_t sm =
      left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
  for (size_t i = 0; i < sval.size(); ++i)
    lines->push_back(VSCat(i < sm    ? lpref
                           : i == sm ? cpref
                                     : rpref,
                           {std::string(1, sval[i])}));
  if (node->root->right_child) {
    Tree* tmptree = new Tree;
    tmptree->root = node->root->right_child;
    Show(tmptree, high, VSCat(rpref, high ? VS({ch_hor, " "}) : VS({ch_hor})),
         VSCat(rpref, high ? VS({ch_rddia, ch_ver}) : VS({ch_rddia})),
         VSCat(rpref, high ? VS({" ", " "}) : VS({" "})), false, false, lines);
  }
  if (root) {
    VS out;
    for (size_t l = 0;; ++l) {
      bool last = true;
      std::string line;
      for (size_t i = 0; i < lines->size(); ++i)
        if (l < (*lines).at(i).size()) {
          line += lines->at(i)[l];
          last = false;
        } else
          line += " ";
      if (last) break;
      out.push_back(line);
    }
    for (size_t i = 0; i < out.size(); ++i) std::cout << out[i] << std::endl;
  }
}
void ShowTree(Tree* node) {
  Show(node, true, std::vector<std::string>(), std::vector<std::string>(),
       std::vector<std::string>(), true, true, nullptr);
}

void Tree::LeftZig(Node* curr) {
  if (curr->parent != nullptr) {
    curr->parent->left_child = curr->right_child;
    curr->right_child = curr->parent;
    curr->parent = curr->parent->parent;
    curr->right_child->parent = curr;
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->parent == nullptr) {
      root = curr;
    } else {
      if (curr->parent->key < curr->key)
        curr->parent->right_child = curr;
      else
        curr->parent->left_child = curr;
    }
  } else {
    throw std::range_error("Can't ZIG root");
  }
}

void Tree::RightZig(Node* curr) {
  if (curr->parent != nullptr) {
    curr->parent->right_child = curr->left_child;
    curr->left_child = curr->parent;
    curr->parent = curr->parent->parent;
    curr->left_child->parent = curr;
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->parent == nullptr) {
      root = curr;
    } else {
      if (curr->parent->key < curr->key)
        curr->parent->right_child = curr;
      else
        curr->parent->left_child = curr;
    }
  } else {
    throw std::range_error("Can't ZIG root");
  }
}

void Tree::LeftZigZig(Node* curr) {
  if (curr->parent != nullptr and curr->parent->parent != nullptr) {
    Tree* tmptree = new Tree;
    tmptree->root = curr->parent->parent;
    tmptree->LeftZig(curr->parent);
    tmptree->LeftZig(curr);
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr and
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr and
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->left_child != nullptr) {
      curr->left_child->left_child->parent = curr->left_child;
    }
    if (curr->parent == nullptr) {
      root = curr;
    } else {
      if (curr->parent->key < curr->key)
        curr->parent->right_child = curr;
      else
        curr->parent->left_child = curr;
    }
  } else {
    throw std::range_error("Can't ZIGZIG this node");
  }
}

void Tree::RightZigZig(Node* curr) {
  if (curr->parent != nullptr and curr->parent->parent != nullptr) {
    Tree* tmptree = new Tree;
    tmptree->root = curr->parent->parent;
    tmptree->RightZig(curr->parent);
    tmptree->RightZig(curr);
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr and
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr and
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->left_child != nullptr) {
      curr->left_child->left_child->parent = curr->left_child;
    }
    if (curr->parent == nullptr) {
      root = curr;
    } else {
      if (curr->parent->key < curr->key)
        curr->parent->right_child = curr;
      else
        curr->parent->left_child = curr;
    }
  } else {
    throw std::range_error("Can't ZIGZIG this node");
  }
}

void Tree::LeftZigZag(Node* curr) {
  if (curr->parent != nullptr and curr->parent->parent != nullptr) {
    Tree* tmptree = new Tree;
    tmptree->root = curr->parent->parent;
    tmptree->RightZig(curr);
    tmptree->LeftZig(curr);
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr and
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr and
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->left_child != nullptr) {
      curr->left_child->left_child->parent = curr->left_child;
    }
    if (curr->parent == nullptr) {
      root = curr;
    } else {
      if (curr->parent->key < curr->key)
        curr->parent->right_child = curr;
      else
        curr->parent->left_child = curr;
    }
  } else {
    throw std::range_error("Can't ZIGZAG this node");
  }
}

void Tree::RightZigZag(Node* curr) {
  if (curr->parent != nullptr and curr->parent->parent != nullptr) {
    Tree* tmptree = new Tree;
    tmptree->root = curr->parent->parent;
    tmptree->LeftZig(curr);
    tmptree->RightZig(curr);
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr and
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr and
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->left_child != nullptr) {
      curr->left_child->left_child->parent = curr->left_child;
    }
    if (curr->parent == nullptr) {
      root = curr;
    } else {
      if (curr->parent->key < curr->key)
        curr->parent->right_child = curr;
      else
        curr->parent->left_child = curr;
    }
  } else {
    throw std::range_error("Can't ZIGZAG this node");
  }
}

void Tree::Splay(Node* curr) {
  while (curr->parent != nullptr) {
    if (curr->parent->parent == nullptr) {
      if (curr->parent->left_child != nullptr and
          curr->parent->left_child->key == curr->key) {
        this->LeftZig(curr);
      } else {
        this->RightZig(curr);
      }
    } else {
      if (curr->parent->parent->left_child != nullptr and
          curr->parent->parent->left_child->left_child != nullptr and
          curr->parent->parent->left_child->left_child->key == curr->key) {
        this->LeftZigZig(curr);
      } else if (curr->parent->parent->left_child != nullptr and
                 curr->parent->parent->left_child->right_child != nullptr and
                 curr->parent->parent->left_child->right_child->key ==
                     curr->key) {
        this->LeftZigZag(curr);
      } else if (curr->parent->parent->right_child != nullptr and
                 curr->parent->parent->right_child->left_child != nullptr and
                 curr->parent->parent->right_child->left_child->key ==
                     curr->key) {
        this->RightZigZag(curr);
      } else {
        this->RightZigZig(curr);
      }
    }
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr and
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr and
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr and
        curr->left_child->left_child != nullptr) {
      curr->left_child->left_child->parent = curr->left_child;
    }
  }
  if (curr->right_child != nullptr and
      curr->right_child->right_child != nullptr) {
    curr->right_child->right_child->parent = curr->right_child;
  }
  if (curr->right_child != nullptr and
      curr->right_child->left_child != nullptr) {
    curr->right_child->left_child->parent = curr->right_child;
  }
  if (curr->left_child != nullptr and
      curr->left_child->right_child != nullptr) {
    curr->left_child->right_child->parent = curr->left_child;
  }
  if (curr->left_child != nullptr and curr->left_child->left_child != nullptr) {
    curr->left_child->left_child->parent = curr->left_child;
  }
}
void Tree::RemoveSplay(int key) {
  this->Find(key);
  this->Remove(this->root->key);
}
Tree::~Tree() {}