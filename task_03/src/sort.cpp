#include "sort.hpp"

#include <algorithm>
#include <vector>

std::vector<int> TakePartVector(const std::vector<int>& data, int first_index,
                                int last_index) {
  if (data.size() == 0) throw std::out_of_range("TakePartVector: empty vector");
  if (first_index >= data.size() || last_index >= data.size() || first_index > last_index) {
    throw std::out_of_range("TakePartVector: wrong indexes");
  }
  std::vector<int> part{};
  for (int i = first_index; i <= last_index; ++i) part.push_back(data[i]);
  return part;
}

std::vector<int> Merge(const std::vector<int>& left,
                       const std::vector<int>& right) {
  std::vector<int> merged_vector{};
  int left_i = 0, right_i = 0;
  while (left_i < left.size() && right_i < right.size()) {
    if (left[left_i] < right[right_i])
      merged_vector.push_back(left[left_i++]);
    else
      merged_vector.push_back(right[right_i++]);
  }
  while (left_i < left.size()) merged_vector.push_back(left[left_i++]);
  while (right_i < right.size()) merged_vector.push_back(right[right_i++]);

  return merged_vector;
}

std::vector<int> MergeSort(const std::vector<int>& data) {
  if (data.size() <= 1) return data;
  std::vector<int> left = TakePartVector(data, 0, data.size() / 2 - 1);
  std::vector<int> right =
      TakePartVector(data, data.size() / 2, data.size() - 1);
  left = MergeSort(left);
  right = MergeSort(right);
  return Merge(left, right);
}