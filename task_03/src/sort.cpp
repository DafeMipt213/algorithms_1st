#include "sort.hpp"

#include <algorithm>
#include <vector>

size_t Partition(std::vector<int>& data, int start, int end) {
  int pivot = data[start];
  size_t count = 0;
  for (size_t i = start + 1; i <= end; i++)
    if (data[i] <= pivot) count++;
  size_t pivot_index = start + count;
  std::swap(data[pivot_index], data[start]);
  size_t i = start;
  size_t j = end;
  while (i < pivot_index && j > pivot_index) {
    while (data[i] <= pivot) i++;
    while (data[j] > pivot) j--;
    if (i < pivot_index && j > pivot_index) std::swap(data[i++], data[j--]);
  }
  return pivot_index;
}

std::vector<int> Sort(const std::vector<int> data, int start, int end) {
  std::vector<int> sortedData = data;
  if (start < end) {
    int p = Partition(sortedData, start, end);
    sortedData = Sort(sortedData, start, p - 1);
    sortedData = Sort(sortedData, p + 1, end);
  }
  return sortedData;
}