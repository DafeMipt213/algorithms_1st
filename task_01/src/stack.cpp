#include "stack.hpp"

#include <algorithm>
#include <cstddef>

void Stack::Push(int value) { _data.push_back(value); }

int Stack::Pop() {
  if (not Is_empty()) {
    int result = this->Peak();
    _data.pop_back();
    return result;
  } else {
    return 0;
  }
}

bool Stack::Is_empty() {
  if (_data.size() == 0) {
    return true;
  } else {
    return false;
  }
}

int Stack::Peak() { return _data[_data.size() - 1]; }

void MinStack::Push(int value) {
  stack.Push(value);

  if (not stack.Is_empty()) {
    if ((stack.Peak() < min.Peak())) {
      min.Push(stack.Peak());
    } else {
      min.Push(min.Peak());
    }
  } else {
    min.Push(stack.Peak());
  }
}

int MinStack::Pop() {
  min.Pop();
  return stack.Pop();
}

int MinStack::Peak() { return stack.Peak(); }

int MinStack::GetMin() { return min.Peak(); }