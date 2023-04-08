#include <iostream>

#include "heap.hpp"

int main() try {
  MinHeap h{};
  h.Push(8);
  h.Push(50);
  h.Push(-10);
  h.Print();
  std::cout << h.Size() << std::endl;
  for (int i = 0; i < 10; ++i) h.Push(10 - i);
  h.Print();
  std::cout << h.Size() << std::endl;
  for (int i = 0; i < 8; ++i) h.Pop();
  h.Print();
  std::cout << h.Size() << std::endl;
} catch (std::exception& e) {
  std::cout << e.what() << std::endl;
}