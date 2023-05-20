#include "sort.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

void Merge(size_t begin, size_t half, size_t end, std::vector<int>& data,
           std::vector<int>& buffer) {
  size_t r = begin;
  size_t l = half;
  size_t i = 0;

  for (; r < half && l < end; ++i) {
    if (data[r] < data[l]) {
      buffer[i] = data[r];
      ++r;
    } else {
      buffer[i] = data[l];
      ++l;
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

void MergeSort(size_t begin, size_t end, std::vector<int>& data,
               std::vector<int>& buffer) {
  if (end - begin == 1) return;

  int half = begin + (end - begin) / 2;

  MergeSort(begin, half, data, buffer);
  MergeSort(half, end, data, buffer);

  Merge(begin, half, end, data, buffer);
}

std::vector<int> Sort(const std::vector<int>& data) {
  if (data.size() == 0) {
    return {};
  }
  std::vector<int> result = data;
  std::vector<int> buffer = data;

  MergeSort(0, result.size(), result, buffer);
  return result;
}