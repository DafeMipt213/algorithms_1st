#include "order_statistics.hpp"
#include <algorithm>
#include <iostream>

int Partition(std::vector<int> &data, int left, int right) {
  int pivot = data[left]; 
  int i = left + 1;
  int j = right;
  while (true) {
    while (i <= j && data[i] <= pivot) {
      i++;
    }
    while (i <= j && data[j] > pivot) {
      j--;
    }
    if (i > j) {
      break;
    }
    std::swap(data[i], data[j]);
  }
  std::swap(data[left], data[j]);
  return j;
}

int GetOrderStatistics(const std::vector<int> &data, size_t n) {
  std::vector<int> copy = data;
  int left = 0;
  int right = copy.size() - 1;
  while (true) {
    int pivotIndex = Partition(copy, left, right);
    if (n == pivotIndex) {
      return copy[pivotIndex];
    } else if (n < pivotIndex) {
      right = pivotIndex - 1;
    } else {
      left = pivotIndex + 1;
    }
  }
}
