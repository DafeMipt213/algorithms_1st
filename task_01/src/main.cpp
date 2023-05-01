#include <iostream>

#include "stack.hpp"

int main() {
  MinStack stack;
  stack.Push(5);
  stack.Push(4);
  stack.Push(3);
  std::cout << stack.GetMin() << "GetMin" << std::endl;
  std::cout << stack.Pop() << "Pop" << std::endl;
  std::cout << stack.GetMin() << "GetMin" << std::endl;
  std::cout << stack.Pop() << "Pop" << std::endl;
  std::cout << stack.GetMin() << "GetMin" << std::endl;
  std::cout << stack.Pop() << "Pop" << std::endl;
  return 0;
}
