#include "order_statistics.hpp"

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  if (n >= data.size() or n < 0 or data.size() == 0) {
    throw std::range_error(
        "Impossible to find this order statistic in this vector((");
  }
  if (data.size() == 1) {
    return data[0];
  }
  std::vector<int> tmp;
  tmp.resize(data.size());
  std::copy(data.begin(), data.end(), tmp.begin());
  int pivot = 0;
  int elem = data[data.size() - 1];
  for (int curr = 0; curr < tmp.size(); ++curr) {
    if (tmp[curr] <= elem) {
      std::swap(tmp[pivot], tmp[curr]);
      pivot += 1;
    }
  }
  if (pivot != 0)
    pivot -= 1;
  else
    pivot = tmp.size() - 1;
  if (pivot == n) {
    return tmp[pivot];
  } else if (pivot > n) {
    std::vector<int> tmp2;
    tmp2.resize(pivot);
    for (int i = 0; i < pivot; ++i) {
      tmp2[i] = tmp[i];
    }
    return GetOrderStatistics(tmp2, n);
  } else {
    std::vector<int> tmp2;
    tmp2.resize(tmp.size() - pivot - 1);
    for (int i = pivot + 1; i < tmp.size(); ++i) {
      tmp2[i - 1 - pivot] = tmp[i];
    }
    return GetOrderStatistics(tmp2, n - pivot - 1);
  }
}