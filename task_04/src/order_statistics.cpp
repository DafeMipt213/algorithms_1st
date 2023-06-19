#include "order_statistics.hpp"

#include <algorithm>
#include <vector>

#include "order_statistics.hpp"

int Partition(std::vector<int>& a, int start, int end) {
  int randint = start + std::rand() % (end - start + 1);
  int pivot = a[randint];
  std::swap(a[randint], a[end]);
  int i = start - 1;
  for (int j = start; j < end; j++) {
    if (a[j] <= pivot) {
      ++i;
      std::swap(a[i], a[j]);
    }
  }
  std::swap(a[i + 1], a[end]);
  return i + 1;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  std::vector<int> tmp(data);
  int left = 0;
  int right = data.size() - 1;
  while (true) {
    int mid = Partition(tmp, left, right);

    if (mid == n) {
      return tmp[mid];
    } else if (n < mid) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
}