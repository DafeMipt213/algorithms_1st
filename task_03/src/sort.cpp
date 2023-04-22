#include "sort.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> Sort(const std::vector<int>& data) {
  if (data.size() < 2) {
    return data;
  }
  int middle = data.size() / 2;
  std::vector<int> left(data.begin(), data.begin() + middle);
  std::vector<int> right(data.begin() + middle, data.end());

  return Merge(Sort(left), Sort(right));
}

std::vector<int> Merge(const std::vector<int> left,
                       const std::vector<int> right) {
  int il = 0;
  int ir = 0;
  std::vector<int> res;
  while (il < left.size() && ir < right.size()) {
    if (left[il] > right[ir]) {
      res.push_back(right[ir]);
      ir++;
    } else {
      res.push_back(left[il]);
      il++;
    }
  }
  while (il < left.size()) {
    res.push_back(left[il]);
    il++;
  }
  while (ir < right.size()) {
    res.push_back(right[ir]);
    ir++;
  }
  return res;
}