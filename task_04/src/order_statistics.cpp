#include "order_statistics.hpp"

int MedianSmall(const std::vector<int>& data) {
  std::vector<int> tmp = {};
  tmp.resize(data.size());
  std::copy(data.begin(), data.end(), tmp.begin());
  for (size_t i = 1; i < data.size(); ++i) {
    int j = i;
    while (j > 0 && tmp[j - 1] > tmp[j]) {
      std::swap(tmp[j], tmp[j - 1]);
      --j;
    }
  }
  if (data.size() >= 4) {
    return tmp[2];
  } else if (data.size() >= 2) {
    return tmp[1];
  }
  return tmp[0];
}

int MedianOfMedians(const std::vector<int>& data) {
  int devider = 0;
  std::vector<int> tmp = {};
  tmp.reserve(data.size() / 5 + 1);
  for (int i = 0; i < data.size() / 5; ++i) {
    devider = i * 5;
    std::vector<int> five = {data[devider], data[devider + 1],
                             data[devider + 2], data[devider + 3],
                             data[devider + 4]};
    tmp.push_back(MedianSmall(five));
  }
  std::vector<int> last = {};
  if (data.size() % 5 != 0) {
    if (data.size() - devider - 1 > 5) {
      devider += 5;
    }
    for (int i = devider; i < data.size(); ++i) {
      last.push_back(data[i]);
    }
    tmp.push_back(MedianSmall(last));
  }
  if (tmp.size() == 1) {
    return tmp[0];
  }
  return MedianOfMedians(tmp);
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  if (n >= data.size() || n < 0 or data.size() == 0) {
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
  int elem = MedianOfMedians(data);
  for (int curr = 0; curr < tmp.size(); ++curr) {
    if (tmp[curr] < elem) {
      std::swap(tmp[pivot], tmp[curr]);
      pivot += 1;
    }
  }
  int elem_index = 0;
  for (int i = 0; i < data.size(); ++i) {
    if (tmp[i] == elem) {
      elem_index = i;
    }
  }
  std::swap(tmp[elem_index], tmp[pivot]);
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
    for (int i = 0; i < pivot; ++i) return GetOrderStatistics(tmp2, n);
  } else {
    std::vector<int> tmp2;
    tmp2.resize(tmp.size() - pivot - 1);
    for (int i = pivot + 1; i < tmp.size(); ++i) {
      tmp2[i - 1 - pivot] = tmp[i];
    }
    return GetOrderStatistics(tmp2, n - pivot - 1);
  }
}