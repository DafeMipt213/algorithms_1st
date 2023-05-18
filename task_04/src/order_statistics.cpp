
#include "order_statistics.hpp"

#include <random>
#include <iostream>

void print(std::vector<int>& data)
{
  for (int elem : data)
    std:: cout << elem << " ";
  std::cout << std::endl;
}

size_t GetRandomIndex(const size_t left, const size_t right)
{
  std::random_device dev;
  std::mt19937 rng(dev());
  std::uniform_int_distribution<std::mt19937::result_type> dist6(left,right);
  size_t rand_index = dist6(rng);
  return rand_index;
}

size_t Partition(std::vector<int>& data, size_t left, size_t right){
  size_t rand_index = GetRandomIndex(left, right);
  while (true){
    while (data[left] < data[rand_index]) ++left;
    while (data[right] > data[rand_index]) --right;
    
    if (left != right) {
      if (data[left] == data[right]){
        if (left == rand_index){
          --right;
        }
        else if (right == rand_index){ 
          ++left;
        }
      }
      else{
      std::swap(data[left], data[right]);
      }
    }
    else{
      break;
    }
  }
  return rand_index;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  n--;
  std::vector<int> tmp(data);
  size_t left = 0;
  size_t right = tmp.size() - 1;

  while (true) {
    size_t rand_element_index = Partition(tmp, left, right);
    print(tmp);
    if (rand_element_index == n){
      return tmp[n];
    }
    else if (rand_element_index < n){
     left = rand_element_index + 1; 
    }
    else if (rand_element_index > n){
      right = rand_element_index - 1;
    }
  }
}
