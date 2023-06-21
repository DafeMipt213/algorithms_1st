#pragma once

#include <memory>
#include <stdexcept>

template <typename T>
class Stack {
 public:
  void Push(T value);
  T Pop();
  int Size();
  ~Stack() {
    while (finish_) {
      if (finish_->back) {
        auto tmp = finish_;
        finish_ = tmp->back;
        delete tmp;
      } else {
        delete finish_;
        finish_ = nullptr;
      }
    }
  }

 private:
  struct Node {
    Node *back = nullptr;
    T value = T();

    Node(Node *back, T value1) : back(back), value(value1) {}
    Node(T value1) : value(value1) {}
    Node() {}
    Node *GetBack() { return this->back; }
    T GetValue() { return this->value; }
  };

  Node *finish_ = nullptr;
  int size_ = 0;
};

template <typename T>
void Stack<T>::Push(T value) {
  if (!finish_) {
    finish_ = new Node(value);
  } else {
    finish_ = new Node(finish_, value);
  }
  size_ += 1;
}

template <typename T>
T Stack<T>::Pop() {
  if (size_ > 1) {
    T value = finish_->GetValue();
    auto tmp = finish_;
    finish_ = tmp->back;
    delete tmp;
    size_ -= 1;
    return value;
  } else if (size_ == 1) {
    T value = finish_->GetValue();
    delete finish_;
    finish_ = nullptr;
    size_ -= 1;
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
      : back(back), value(value1), min_value(value2) {}
  NodeWithMin(T value1) : back(nullptr), value(value1), min_value(value1) {}
};

template <typename T>
class MinStack {
 public:
  void Push(T value);
  T Pop();
  T GetMin();
  ~MinStack() {
    while (finish_) {
      auto tmp = finish_;
      finish_ = tmp->back;
      delete tmp;
    }
  }

 private:
  NodeWithMin<T> *finish_ = nullptr;
  int size_ = 0;
};

template <typename T>
void MinStack<T>::Push(T value) {
  if (!finish_) {
    finish_ = new NodeWithMin<T>(value);
  } else {
    T min_value = (finish_->min_value < value) ? finish_->min_value : value;
    finish_ = new NodeWithMin<T>(finish_, value, min_value);
  }
  size_ += 1;
}

template <typename T>
T MinStack<T>::Pop() {
  if (size_ > 1) {
    T value = finish_->value;
    auto tmp = finish_;
    finish_ = tmp->back;
    delete tmp;
    size_ -= 1;
    return value;
  } else if (size_ == 1) {
    T value = finish_->value;
    delete finish_;
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