#include "sort.hpp"

#include <vector>

std::vector<int> Join(std::vector<int>::iterator start_1,
                      std::vector<int>::iterator end_1,
                      std::vector<int>::iterator start_2,
                      std::vector<int>::iterator end_2) {
  std::vector<int> result(end_1 - start_1 + end_2 - start_2);
  size_t i = 0;
  while (start_1 < end_1 || start_2 < end_2) {
    if (start_1 == end_1) {
      result[i] = *start_2;
      ++start_2;
    } else if (start_2 == end_2) {
      result[i] = *start_1;
      ++start_1;
    } else if (*start_1 < *start_2) {
      result[i] = *start_1;
      ++start_1;
    } else {
      result[i] = *start_2;
      ++start_2;
    }
    ++i;
  }
  return result;
}

std::vector<int> Slice(const std::vector<int>& data, size_t start, size_t end) {
  std::vector<int> result;
  result.insert(result.end(), data.begin() + start, data.begin() + end);
  return result;
}

std::vector<int> MergeSort(const std::vector<int>& data) {
  if (data.size() <= 1) return data;
  std::vector<int> result;
  size_t middle = data.size() / 2;
  std::vector<int> data_l = MergeSort(Slice(data, 0, middle));
  std::vector<int> data_r = MergeSort(Slice(data, middle, data.size()));
  result = Join(data_l.begin(), data_l.end(), data_r.begin(), data_r.end());
  return result;
}
