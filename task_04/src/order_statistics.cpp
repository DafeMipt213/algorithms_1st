#include "order_statistics.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

int GetOrderStatisticsHelper(std::vector<int>& data, size_t left, size_t right, size_t n) {
  if (left == right) {
    return data[left];
  }

  size_t pivot_index = left + (right - left) / 2;
  pivot_index = Partition(data, left, right, pivot_index);

  if (n == pivot_index) {
    return data[n];
  } else if (n < pivot_index) {
    return GetOrderStatisticsHelper(data, left, pivot_index - 1, n);
  } else {
    return GetOrderStatisticsHelper(data, pivot_index + 1, right, n);
  }
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  if (n >= data.size()) {
    throw std::out_of_range("Invalid order statistic");
  }

  std::vector<int> temp_data = data;  // Create a copy of the input data
  return GetOrderStatisticsHelper(temp_data, 0, temp_data.size() - 1, n);
}

size_t Partition(std::vector<int>& data, size_t left, size_t right, size_t pivot_index) {
  int pivot_value = data[pivot_index];
  std::swap(data[pivot_index], data[right]);
  size_t store_index = left;
  for (size_t i = left; i < right; ++i) {
    if (data[i] < pivot_value) {
      std::swap(data[i], data[store_index]);
      ++store_index;
    }
  }

  std::swap(data[store_index], data[right]);
  return store_index;
}
