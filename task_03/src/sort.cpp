#pragma once

#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> Sort(const std::vector<int>& data) {
  std::vector<int> v1 = data;
  if (v1.size() <= 1) {
    return v1;
  }

  int mid = v1.size() / 2;
  auto begin = v1.begin();

  std::advance(begin, mid);

  std::vector<int> v2(begin, v1.end());

  v1.erase(begin, v1.end());
  v1 = Sort(v1);
  v2 = Sort(v2);
  std::vector<int> result(v1.size() + v2.size());
  int i = 0, j = 0, k = 0;
  // Merge two vectors
  while (i < v1.size() && j < v2.size()) {
    if (v1[i] <= v2[j]) {
      result[k] = v1[i];
      i++;
    } else {
      result[k] = v2[j];
      j++;
    }
    k++;
  }

  while (i < v1.size()) {
    result[k] = v1[i];
    i++;
    k++;
  }

  while (j < v2.size()) {
    result[k] = v2[j];
    j++;
    k++;
  }
  return result;
}