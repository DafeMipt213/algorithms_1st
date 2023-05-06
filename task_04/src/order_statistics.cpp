#include "order_statistics.hpp"

#include <algorithm>

std::vector<int> Sort(const std::vector<int>& data) {
  if (data.size() <= 1) {
    return data;
  }

  size_t mid = data.size() / 2;
  auto mid_it = data.begin();
  std::advance(mid_it, mid);
  std::vector<int> v1(data.begin(), mid_it);
  std::vector<int> v2(mid_it, data.end());
  v1 = Sort(v1);
  v2 = Sort(v2);
  std::vector<int> result;
  int i = 0, j = 0, k = 0;
  while (i < v1.size() && j < v2.size()) {
    if (v1[i] <= v2[j]) {
      result.insert(result.end(), v1[i]);
      i++;
    } else {
      result.insert(result.end(), v2[j]);
      j++;
    }
  }
  if (i < v1.size()) {
    result.insert(result.end(), std::next(v1.begin(), i), v1.end());
  }
  if (j < v2.size()) {
    result.insert(result.end(), std::next(v2.begin(), j), v2.end());
  }
  return result;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  std::vector<int> tmp(data);
  tmp = Sort(tmp);
  return tmp[n];
}
