#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
struct Node {
 private:
  Node<T> *back = nullptr;
  Node<T> *next = nullptr;
  T value = T();

 public:
  Node(Node<T> *back, T value1) : back(back), value(value1) {}
  Node(T value1) : value(value1) {}
  Node() {}
  Node *GetBack() { return this->back; }
  Node *GetNext() { return this->next; }
  T GetValue() { return this->value; }
};

template <typename T>
class Stack {
 public:
  void Push(T value);
  T Pop();
  int Size();
  ~Stack() {
    if (start_) delete start_;
    if (finish_) delete finish_;
  }

 private:
  Node<T> *start_ = nullptr;
  Node<T> *finish_ = nullptr;
  int size_ = 0;
};

template <typename T>
void Stack<T>::Push(T value) {
  if (!start_) {
    Node<T> *new_Node = new Node<T>(value);
    start_ = new_Node;
    finish_ = new_Node;
  } else {
    Node<T> *new_Node = new Node<T>(finish_, value);
    auto tmp = finish_->GetNext();
    tmp = new_Node;
    finish_ = new_Node;
  }
  size_ += 1;
}

template <typename T>
T Stack<T>::Pop() {
  if (size_ > 1) {
    T value = finish_->GetValue();
    auto temp = new Node<T>(finish_, 0);
    auto tmp = finish_->GetBack()->GetNext();
    tmp = nullptr;
    finish_ = finish_->GetBack();
    size_ -= 1;
    delete temp;
    return value;
  } else if (size_ == 1) {
    T value = finish_->GetValue();
    auto temp = new Node<T>(finish_, 0);
    start_ = nullptr;
    finish_ = nullptr;
    size_ -= 1;
    delete temp;
    return value;
  } else
    throw std::out_of_range("Empty Stack");
}

template <typename T>
int Stack<T>::Size() {
  return size_;
}

template <typename T>
struct NodeWithMin {
 public:
  NodeWithMin<T> *back;
  NodeWithMin<T> *next;
  T value;
  T min_value;
  NodeWithMin(NodeWithMin *back, T value1, T value2)
      : next(nullptr), back(back), value(value1), min_value(value2) {}
  NodeWithMin(T value1)
      : back(nullptr), next(nullptr), value(value1), min_value(value1) {}
};

template <typename T>
class MinStack {
 public:
  void Push(T value);
  T Pop();
  T GetMin();
  ~MinStack() {
    if (start_) delete start_;
    if (finish_) delete finish_;
  }

 private:
  NodeWithMin<T> *start_ = nullptr;
  NodeWithMin<T> *finish_ = nullptr;
  int size_ = 0;
};

template <typename T>
void MinStack<T>::Push(T value) {
  if (!start_) {
    NodeWithMin<T> *new_Node = new NodeWithMin<T>(value);
    start_ = new_Node;
    finish_ = new_Node;
  } else {
    T min_value = (finish_->min_value < value) ? finish_->min_value : value;
    NodeWithMin<T> *new_Node = new NodeWithMin<T>(finish_, value, min_value);
    finish_->next = new_Node;
    finish_ = new_Node;
  }
  size_ += 1;
}

template <typename T>
T MinStack<T>::Pop() {
  if (size_ > 1) {
    T value = finish_->value;
    auto temp = std::unique_ptr<NodeWithMin<T>>(finish_);
    finish_->back->next = nullptr;
    finish_ = finish_->back;
    size_ -= 1;
    return value;
  } else if (size_ == 1) {
    T value = finish_->value;
    auto temp = std::unique_ptr<NodeWithMin<T>>(finish_);
    start_ = nullptr;
    finish_ = nullptr;
    size_ = 0;
    return value;
  } else
    throw std::out_of_range("Empty MinStack");
}

template <typename T>
T MinStack<T>::GetMin() {
  if (size_ > 0)
    return finish_->min_value;
  else
    throw std::out_of_range("Empty MinStack");
}