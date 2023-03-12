#include "sort.hpp"

#include <algorithm>
#include <vector>

std::vector<int> Merge(const std::vector<int>& data1,
                       const std::vector<int>& data2) {
  int i = 0;
  int j = 0;
  std::vector<int> DataMerged = {};
  while (i != data1.size() and j != data2.size()) {
    if (data1[i] > data2[j]) {
      DataMerged.push_back(data2[j]);
      j++;
    } else {
      DataMerged.push_back(data1[i]);
      i++;
    }
  }
  while (i != data1.size()) {
    {
      DataMerged.push_back(data1[i]);
      i++;
    }
  }
  while (j != data2.size()) {
    {
      DataMerged.push_back(data2[j]);
      j++;
    }
  }
  return DataMerged;
}

std::vector<int> SplitLeft(const std::vector<int>& data) {
  std::vector<int> left = {};
  left.reserve(data.size() / 2);
  for (unsigned long i = 0; i < data.size() / 2; ++i) {
    left.push_back(data[i]);
  }
  return left;
}

std::vector<int> SplitRight(const std::vector<int>& data) {
  std::vector<int> right = {};
  right.reserve(data.size() / 2);
  for (unsigned long i = data.size() / 2; i < data.size(); ++i) {
    right.push_back(data[i]);
  }
  return right;
}

std::vector<int> MergeSort(const std::vector<int>& data) {
  if (data.size() <= 1) {
    return data;
  }
  std::vector<int> left = SplitLeft(data);
  std::vector<int> right = SplitRight(data);
  std::vector<int> sorted_left = MergeSort(left);
  std::vector<int> sorted_right = MergeSort(right);
  return Merge(sorted_left, sorted_right);
}