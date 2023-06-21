#include "sort.hpp"

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
 
void qsort(int* begin, int* end) {
  if (begin >= end) {
      return;
  }
  int* pivot = partition(begin, end);
 
  qsort(begin, pivot - 1); 
  qsort(pivot + 1, end);
}

std::vector<int> Sort(const std::vector<int>& data) {
  std::vector<int> result = data;

  qsort(&result[0], &result[result.size() - 1]);

  return result;
}