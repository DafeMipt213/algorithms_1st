#pragma once

#include <vector>

template <typename T>
std::vector<T> QuickSort(const std::vector<T> &data) {
  std::vector<T> result = data;
  if (data.empty()) return result;
  std::vector<int> left_and_right = {0, int(data.size()) - 1};
  do {
    int right = left_and_right.back();
    left_and_right.pop_back();
    int left = left_and_right.back();
    left_and_right.pop_back();

    int i = left;
    int j = right;

    T mid_elem = result[(j + i) / 2];
    do {
      while (result[i] < mid_elem) ++i;
      while (result[j] > mid_elem) --j;
      if (i <= j) {
        std::swap(result[i], result[j]);
        ++i;
        --j;
      }
    } while (i <= j);

    if (left < j) {
      left_and_right.push_back(left);
      left_and_right.push_back(j);
    }

    if (right > i) {
      left_and_right.push_back(i);
      left_and_right.push_back(right);
    }

  } while (!left_and_right.empty());

  return result;
}
