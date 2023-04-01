#include <iostream>
#include <vector>
#include "heap.hpp"
#include <cstddef>
#include <stdexcept>

using namespace std;

void MinHeap::Push(int n) {
   array.push_back(n);
   Sift_up(array.size()-1);
}

int MinHeap::Pop() {
  if (array.empty()) throw std::out_of_range("Empty heap");
  int elem = array[0];
  array[0] = array[array.size()-1];
  array.pop_back();
  Sift_down(0);
  return elem;
}

size_t MinHeap::Size() { return array.size(); }

void MinHeap::Sift_up(int index)
{
  if (index > 0)
  {
    int parent = array[(index-1)/2];
    if (parent > array[index])
    {
      array[(index-1)/2] = array[index];
      array[index] = parent;
    }
    Sift_up((index-1)/2);
  }
  return;
}
void MinHeap::Sift_down(int index)
{
  if (array.size() == 0)
    return;
  if((2*index+1) < (array.size()))
  {
    int child_index = 2*index + 1;
    int child2_index = 2*index + 2;
    if (2*index + 2 < (array.size()))
    {
      if (array[child_index] > array[child2_index])
        child_index = child2_index;
    }
    int child = array[child_index];
    if(array[index] < child)
      return;
    else
    {
      array[child_index] = array[index];
      array[index] = child;
      Sift_down(child_index);
    }
  };
}
