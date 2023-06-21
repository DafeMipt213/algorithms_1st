#pragma once

#include <stdexcept>
#include <vector>

std::vector<int> CalculateDaysBeforWarmup(const std::vector<float> &temerature);

template <typename T>
class Stack {
 public:
  void Push(T value);
  T Pop();
  T Top();
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
T Stack<T>::Top() {
  return finish_->value;
}

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