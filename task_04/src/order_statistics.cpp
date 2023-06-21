#include "order_statistics.hpp"

#include <algorithm>
#include <stdexcept>

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  if (n >= data.size()) {
    throw std::out_of_range("Invalid value of n");
  }

  std::vector<int> tmp(data);
  std::sort(tmp.begin(), tmp.end());

  return tmp[n];
}
