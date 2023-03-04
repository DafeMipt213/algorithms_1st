#include "heap.hpp"

#include <cstddef>
#include <stdexcept>



void MinHeap::SiftDown(int elem)
{
  int tmp = 0;
  while (2 * elem + 2 < data_.size())
  {
    if (data_[elem] > data_[2 * elem + 1] and data_[elem] < data_[2 * elem + 2]){
      tmp = data_[elem];
      data_[elem] = data_[2 * elem + 1];
      data_[2 * elem + 1] = tmp;
    } else if(data_[elem] < data_[2 * elem + 1] and data_[elem] > data_[2 * elem + 2]){
      tmp = data_[elem];
      data_[elem] = data_[2 * elem + 2];
      data_[2 * elem + 2] = tmp;
    } else if(data_[elem] > data_[2 * elem + 1] and data_[elem] > data_[2 * elem + 2])
    {
      if(data_[2 * elem + 1] > data_[2 * elem + 2])
      {
        data_[elem] = data_[elem * 2 + 2];
      } else {
        data_[elem] = data_[elem * 2 + 1];
      }
    } else{
      return;
    }
  }
}

void MinHeap::SiftUp(int elem)
{
  int tmp = 0;
  while(true)
  {
    if (elem == 0)
    {
      return;
    }
    if(data_[elem] < data_[(elem - 1) / 2]) {
      tmp = data_[elem];
      data_[(elem - 1) / 2] = data_[elem];
      data_[elem] = tmp;
    } else {
      return;
    }
  }
}




void MinHeap::Push(int n) { 
  data_.push_back(n);
  SiftUp(data_.size() - 1);
 }


int MinHeap::Pop() {
  if (data_.empty()) throw std::out_of_range("Empty heap");
  auto result = data_[0];
  data_[0] = data_[data_.size() - 1];
  SiftDown(0);

  return result;
}

size_t MinHeap::Size() { return data_.size(); }
