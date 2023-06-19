#include "sort.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> Merge(const std::vector<int>& left,
                       const std::vector<int>& right) {
  int index_left = 0;
  int index_right = 0;
  std::vector<int> res;
  while (index_left < left.size() && index_right < right.size()) {
    if (left[index_left] > right[index_right]) {
      res.push_back(right[index_right]);
      index_right++;
    } else {
      res.push_back(left[index_left]);
      index_left++;
    }
  }
  while (index_left < left.size()) {
    res.push_back(left[index_left]);
    index_left++;
  }
  while (index_right < right.size()) {
    res.push_back(right[index_right]);
    index_right++;
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