#include <iostream>
#include <heap.hpp>

int main() {  
  MinHeap heap;
  heap.Push(1);
  heap.Push(2);
  heap.Push(3);              // [1, 2, 3]
 std::cout<<heap.Pop()<<std::endl;  // [2, 3] -> 1
 std::cout<<heap.Pop()<<std::endl;  // [3] -> 2
 std::cout<<heap.Pop()<<std::endl;  // [] -> 3
}
