#include "Quick_Sort.hpp"

int partition(std::vector<int>& values, int left, int right) {
  int pivotIndex = left + (right - left) / 2;
  int pivotValue = values[pivotIndex];
  int i = left, j = right;
  int temp;
  while (i <= j) {
    while (values[i] < pivotValue) {
      i++;
    }
    while (values[j] > pivotValue) {
      j--;
    }
    if (i <= j) {
      temp = values[i];
      values[i] = values[j];
      values[j] = temp;
      i++;
      j--;
    }
  }
  return i;
}
std::vector<int> Sort(const std::vector<int>& data) {
  std::vector<int> tmp(data);
  return Quick_Sort(tmp, 0, tmp.size() - 1);
}
std::vector<int> Quick_Sort(std::vector<int>& data, int start, int end) {
  if (start < end) {
    int pivot = partition(data, start, end);
    Quick_Sort(data, start, pivot - 1);
    Quick_Sort(data, pivot, end);
  }
  return data;
}