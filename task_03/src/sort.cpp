#include "sort.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> Merge(const std::vector<int>& left,
                       const std::vector<int>& right) {
  int iter_left = 0;
  int iter_right = 0;
  std::vector<int> res;
  while (iter_left < left.size() && iter_right < right.size()) {
    if (left[iter_left] > right[iter_right]) {
      res.push_back(right[iter_right]);
      iter_right++;
    } else {
      res.push_back(left[iter_left]);
      iter_left++;
    }
  }
  while (iter_left < left.size()) {
    res.push_back(left[iter_left]);
    iter_left++;
  }
  while (iter_right < right.size()) {
    res.push_back(right[iter_right]);
    iter_right++;
  }
  return res;
}

std::vector<int> Sort(const std::vector<int>& data) {
  if (data.size() < 2) {
    return data;
  }
  size_t middle = data.size() / 2;
  std::vector<int> left(data.begin(), data.begin() + middle);
  std::vector<int> right(data.begin() + middle, data.end());

  return Merge(Sort(left), Sort(right));
}
