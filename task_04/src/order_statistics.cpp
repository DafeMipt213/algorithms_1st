#include "order_statistics.hpp"

size_t Partition(std::vector<int>& vec, size_t left, size_t right) {
  int middle = vec[(left + right + 1) / 2];
  while (true) {
    while (vec[left] < middle) ++left;

    while (vec[right] > middle) --right;

    if (left >= right) break;

    if (vec[left] > vec[right]) std::swap(vec[right], vec[left]);

    left += 1;
  }
  return left;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  std::vector<int> tmp(data);

  size_t left = 0;
  size_t right = data.size() - 1;
  n--;

  while (true) {
    size_t pivot = Partition(tmp, left, right);

    if (pivot == n) {
      return tmp[pivot];
    } else if (pivot > n) {
      right = pivot - 1;
    } else {
      left = pivot + 1;
    }

    if (left == right) return tmp[left];
  }
}