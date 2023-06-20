#include "sort.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using iter = std::vector<int>::iterator;

void Merge(iter left, iter mid, iter right) {
  std::vector<int> left_vector(left, mid);
  std::vector<int> right_vector(mid, right);

  iter left_index = left_vector.begin();
  iter right_index = right_vector.begin();

  while (left_index != left_vector.end() && right_index != right_vector.end()) {
    if (*left_index < *right_index) {
      *left = *left_index;
      ++left_index;
    } else {
      *left = *right_index;
      right_index++;
    }
    left++;
  }

  copy(left_index, left_vector.end(), left);
}

void InnerSort(iter left, iter right) {
  int dist = distance(left, right);
  if (dist > 1) {
    iter mid = left + (dist) / 2;

    InnerSort(left, mid);
    InnerSort(mid, right);

    Merge(left, mid, right);
  }
}

// void Sort(iter left, iter right) {
std::vector<int> Sort(std::vector<int> vec) {
  if (vec.size() > 1) {
    iter left = vec.begin();
    iter right = vec.end();
    InnerSort(left, right);
  }

  return vec;
}
