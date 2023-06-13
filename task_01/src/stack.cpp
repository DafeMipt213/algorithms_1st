#include <iostream>
#include <stack.hpp>
#include <vector>

void Stack::Push(int value) { data.push_back(value); }
int Stack::Pop() {
  if (data.empty()) {
    return -1;
  }
  int back = data.back();
  data.pop_back();
  return back;
}
void MinStack::Push(int val) {
  data.push_back(val);
  if (data.empty() || val <= min) {
    min = val;
  }
}
int MinStack::Pop() {
  if (data.empty()) {
    return -1;
  }

  int back = data.back();
  data.pop_back();

  min = INT16_MAX;
  for (int i : data) {
    if (min > i) {
      min = i;
    }
    std::cout << i << std::endl;
  }
  return back;
}
int MinStack::GetMin() { return min; }
