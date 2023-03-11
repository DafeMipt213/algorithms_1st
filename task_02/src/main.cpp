#include <iostream>

#include "heap.hpp"
// test of merge (it works)
int main() {
  MinHeap heap1;
  heap1.Push(1);
  heap1.Push(4);
  heap1.Push(7);
  MinHeap heap2;
  heap2.Push(2);
  heap2.Push(3);
  heap2.Push(5);
  heap1 = heap2 + heap1;
  return 0;
}
 