#include <iostream>
#include "heap.hpp"
using namespace std;

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
    cout << myHeap.Pop() << endl; 
    myHeap.printHeap();
    return 0; 
}


