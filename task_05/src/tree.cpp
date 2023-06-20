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
    Node* tmpnode;
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
          Splay(tmpnode->right_child);
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
          Splay(tmpnode->left_child);
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
    Node* tmpnode;
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
          Splay(tmpnode->right_child);
          return;
        } else {
          tmpnode = tmpnode->right_child;
        }
      } else if (key == tmpnode->key) {
        tmpnode->data = value;
        Splay(tmpnode);
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
    Node* tmpnode = root;
    while (true) {
      if (key > tmpnode->key) {
        if (root->right_child == nullptr) {
          throw std::range_error("No element with such key in a tree");
        } else {
          tmpnode = tmpnode->right_child;
        }
      } else if (key == tmpnode->key) {
        Splay(tmpnode);
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
    if (root->left_child == nullptr && root->right_child == nullptr) {
      root = nullptr;
    } else if (root->left_child != nullptr && root->right_child == nullptr) {
      root = root->left_child;
    } else if (root->left_child == nullptr && root->right_child != nullptr) {
      root = root->right_child;
    } else {
      Node* best_child;
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
  Node* tmpnode = root;
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
        if (father->left_child != nullptr && father->left_child->key == key)
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
        if (father->left_child != nullptr && father->left_child->key == key)
          father->left_child = tmpnode->right_child;
        else
          father->right_child = tmpnode->right_child;
        tmpnode = tmpnode->right_child;
      } else {
        Node* best_child;
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
    Tree* tmptree;
    tmptree->root = curr->parent->parent;
    tmptree->LeftZig(curr->parent);
    tmptree->LeftZig(curr);
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr &&
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr &&
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
  if (curr->parent != nullptr && curr->parent->parent != nullptr) {
    Tree* tmptree;
    tmptree->root = curr->parent->parent;
    tmptree->RightZig(curr->parent);
    tmptree->RightZig(curr);
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr &&
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr &&
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
  if (curr->parent != nullptr && curr->parent->parent != nullptr) {
    Tree* tmptree;
    tmptree->root = curr->parent->parent;
    tmptree->RightZig(curr);
    tmptree->LeftZig(curr);
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr &&
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr &&
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
  if (curr->parent != nullptr && curr->parent->parent != nullptr) {
    Tree* tmptree;
    tmptree->root = curr->parent->parent;
    tmptree->LeftZig(curr);
    tmptree->RightZig(curr);
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr &&
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr &&
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
      if (curr->parent->left_child != nullptr &&
          curr->parent->left_child->key == curr->key) {
        LeftZig(curr);
      } else {
        RightZig(curr);
      }
    } else {
      if (curr->parent->parent->left_child != nullptr &&
          curr->parent->parent->left_child->left_child != nullptr &&
          curr->parent->parent->left_child->left_child->key == curr->key) {
        LeftZigZig(curr);
      } else if (curr->parent->parent->left_child != nullptr &&
                 curr->parent->parent->left_child->right_child != nullptr &&
                 curr->parent->parent->left_child->right_child->key ==
                     curr->key) {
        LeftZigZag(curr);
      } else if (curr->parent->parent->right_child != nullptr &&
                 curr->parent->parent->right_child->left_child != nullptr &&
                 curr->parent->parent->right_child->left_child->key ==
                     curr->key) {
        RightZigZag(curr);
      } else {
        RightZigZig(curr);
      }
    }
    if (curr->right_child != nullptr) {
      curr->right_child->parent = curr;
    }
    if (curr->left_child != nullptr) {
      curr->left_child->parent = curr;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->right_child != nullptr) {
      curr->right_child->right_child->parent = curr->right_child;
    }
    if (curr->right_child != nullptr &&
        curr->right_child->left_child != nullptr) {
      curr->right_child->left_child->parent = curr->right_child;
    }
    if (curr->left_child != nullptr &&
        curr->left_child->right_child != nullptr) {
      curr->left_child->right_child->parent = curr->left_child;
    }
    if (curr->left_child != nullptr &&
        curr->left_child->left_child != nullptr) {
      curr->left_child->left_child->parent = curr->left_child;
    }
  }
  if (curr->right_child != nullptr &&
      curr->right_child->right_child != nullptr) {
    curr->right_child->right_child->parent = curr->right_child;
  }
  if (curr->right_child != nullptr &&
      curr->right_child->left_child != nullptr) {
    curr->right_child->left_child->parent = curr->right_child;
  }
  if (curr->left_child != nullptr && curr->left_child->right_child != nullptr) {
    curr->left_child->right_child->parent = curr->left_child;
  }
  if (curr->left_child != nullptr && curr->left_child->left_child != nullptr) {
    curr->left_child->left_child->parent = curr->left_child;
  }
}
void Tree::RemoveSplay(int key) {
  Find(key);
  Remove(this->root->key);
}
Tree::~Tree() {}