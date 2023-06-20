#include "order_statistics.hpp"

#include <algorithm>
#include <vector>

size_t Partition(std::vector<int>& data, size_t left, size_t right) {
  int pivot = data[right];
  size_t j = left;
  for (size_t i = left; i < right; ++i) {
    if (data[i] < pivot) {
      std::swap(data[i], data[j]);
      j++;
    }
  }
  std::swap(data[j], data[right]);
  return j;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  size_t left = 0;
  size_t right = data.size() - 1;
  std::vector<int> tmp = data;

  while (true) {
    size_t mid = Partition(tmp, left, right);

    if (mid == n)
      return tmp[mid];
    else if (n < mid) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
}
