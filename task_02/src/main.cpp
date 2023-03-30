#include <iostream>
#include "heap.hpp"

int main() { 
    MinHeap heap;
    heap.Push(1);
    heap.Push(2);
    heap.Push(3);
    std::cout << heap.Pop() << std::endl;
    std::cout << heap.Pop() << std::endl;
    std::cout << heap.Pop() << std::endl;

    return 0; 
}
