#include <iostream>

#include "heap.hpp"

int main() {
  MinHeap myHeap;
  myHeap.Push(3);
  myHeap.printHeap();
  myHeap.Push(10);
  myHeap.printHeap();
  myHeap.Push(5);
  myHeap.printHeap();
  myHeap.Push(8);
  myHeap.printHeap();
  myHeap.Push(1);
  myHeap.printHeap();
  std::cout << myHeap.Pop() << std::endl;
  myHeap.printHeap();
  return 0;
}
