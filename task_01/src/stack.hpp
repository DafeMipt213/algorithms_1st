#pragma once

#include <stack>
#include <stdexcept>
#include <vector>

class Stack {
 public:
  Stack() = default;
  Stack(std::vector<int>&& v);
  Stack(const std::vector<int>& v);

  void Push(int value);
  int Pop();

  size_t Size() { return data_.size(); }
  int GetLast();
  bool Empty() { return data_.size() == 0; }

 private:
  std::vector<int> data_{};
};

class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  Stack data_;
  Stack mins_;
};