#include "order_statistics.hpp"

#include <algorithm>
#include <vector>

size_t Partition(std::vector<int>& data, size_t left, size_t right) {
  // Выбираем рандомный pivot
  size_t pivot_index = left + rand() % (right - left + 1);
  size_t pivot = data[pivot_index];
  std::swap(data[pivot_index], data[right]);

  size_t i= left - 1;
  for (size_t j = left; j < right; j++) {
    if (data[j] <= pivot) {
      i++;
      std::swap(data[i], data[j]);
    }
  }
  std::swap(data[i + 1], data[right]);
  return i + 1;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  std::vector<int> tmp_data = data;
  int left = 0, right = data.size() - 1;
  while (true) {
    int middle = Partition(tmp_data, left, right);

    if (middle == n)
      return tmp_data[middle];
    else if (n < middle)
      right = middle;
    else
      left = middle + 1;
  }
}