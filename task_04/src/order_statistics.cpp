#include "order_statistics.hpp"

#include <algorithm>

int FindOrderStatistic(std::vector<int>& vec, int low, int high, int k) {
  int median = FindMedian(vec, low, low + (high - low) / 2, high);
  std::swap(vec[low], vec[median]);
  int h = BreakPartition(vec, low, high);
  if (h == k - 1) return h;
  if (h < k - 1) {
    return FindOrderStatistic(vec, h + 1, high, k);
  }
  return FindOrderStatistic(vec, low, h - 1, k);
}

int GetOrderStatistics(std::vector<int>& data, size_t n) {
  int k_ = FindOrderStatistic(data, 0, data.size() - 1, n + 1);
  return data[k_];
}

int FindMedian(std::vector<int> vec, int low, int med, int high) {
  if (vec[low] <= vec[med]) {
    if (vec[med] <= vec[high]) {
      return med;
    }
  } else {
    if (vec[low] <= vec[high]) {
      return low;
    }
  }
  return high;
}

int BreakPartition(std::vector<int>& vec, int low, int high) {
  int i = low + 1, j = high;
  int SupportElement = vec[low];
  while (true) {
    while (i < high && vec[i] < SupportElement) ++i;
    while (vec[j] > SupportElement) --j;
    if (i >= j) break;
    std::swap(vec[i], vec[j]);
    i++;
    j--;
  }
  std::swap(vec[low], vec[j]);
  return j;
}