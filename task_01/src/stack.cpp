#include "stack.hpp"

#include <algorithm>

void Stack::Push(int value) { _data.push_back(value); }

int Stack::Pop() {
  int ret_value = _data[_data.size() - 1];
  _data.erase(_data.begin() + _data.size() - 1);
  return ret_value;
}

void MinStack::Push(int value) {
  if (_data.size() > 0) {
    int min_num = std::min(value, _data[0].second);
    _data.push_back(std::pair<int, int>(value, min_num));
  } else {
    _data.push_back(std::pair<int, int>(value, value));
  }
}

int MinStack::Pop() {
  int ret_value = _data[_data.size() - 1].first;
  _data.erase(_data.begin() + _data.size() - 1);
  return ret_value;
}

int MinStack::GetMin() { return _data[_data.size() - 1].second; }