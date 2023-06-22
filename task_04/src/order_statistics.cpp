#include "order_statistics.hpp"

#include <algorithm>

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

size_t GetOrderStatistics(std::vector<int>& data, size_t k) {
  int left = 0, right = data.size() - 1;
  while (true) {
    size_t pivot_index = Partition(data, left, right);
    if (pivot_index == k) {
      return data[pivot_index];
    } else if (k <= pivot_index)
      right = pivot_index;
    else
      left = pivot_index + 1;
  }
}
