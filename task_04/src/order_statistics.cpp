#include "order_statistics.hpp"

#include <algorithm>
#include <type_traits>
#include <vector>

size_t partition(std::vector<int>& arr, size_t l, size_t r) {
  int i = l - 1, pivot = arr[r];
  for (int j = l; j < r; j++) {
    if (arr[j] <= pivot) {
      ++i;
      std::swap(arr[i], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[r]);
  return i + 1;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  size_t left = 0, right = data.size() - 1;
  std::vector<int> tmp = data;
  while (true) {
    size_t mid = partition(tmp, left, right);

    if (mid == n)
      return tmp[mid];
    else if (n < mid) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
}
