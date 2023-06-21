#include "order_statistics.hpp"

#include <algorithm>

int* partition(int* begin, int* end) {
  int pivot = *end;
 
  int* p_ind = begin;
 
  for (int* i = begin; i < end; i++) {
      if (*i <= pivot) {
        std::swap(*i, *p_ind);
        p_ind++;
      }
  }
  std::swap (*p_ind, *end);
 
  return p_ind;
}

int findOS(int* left, int* right, size_t k) {
  while(true) {
    int* midi = partition(left, right);
    int mid = midi - left;
    if (mid == k) {
      return *midi;
    }
    else if (k < mid) {
      right = midi;
    }
    else {
      left = midi + 1;
    }
  }
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  std::vector<int> tmp(data);

  std::sort(tmp.begin(), tmp.end());

  return tmp[n];
}
