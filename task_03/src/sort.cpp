#include "sort.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

void merge(int begin, int half, int end, std::vector<int>& data,
           std::vector<int>& buffer) {
  int r = begin;
  int l = half;
  int i = 0;

  for (; r < half && l < end; ++i) {
    if (data[r] < data[l]) {
      buffer[i] = data[r];
      r++;
    } else {
      buffer[i] = data[l];
      l++;
    }
  }

  for (; r < half; ++i, ++r) {
    buffer[i] = data[r];
  }

  for (; l < end; ++i, ++l) {
    buffer[i] = data[l];
  }

  for (int j = 0; j < i; ++j) {
    data[begin] = buffer[j];
    ++begin;
  }
}

void mergeSort(int begin, int end, std::vector<int>& data,
               std::vector<int>& buffer) {
  if (end - begin == 1) return;

  int half = begin + (end - begin) / 2;

  mergeSort(begin, half, data, buffer);
  mergeSort(half, end, data, buffer);

  merge(begin, half, end, data, buffer);
}

std::vector<int> Sort(const std::vector<int>& data) {
  if (data.size() == 0) {
    return {};
  }

  std::vector<int> result = data;
  std::vector<int> buffer = data;

  mergeSort(0, result.size(), result, buffer);
  return result;
}