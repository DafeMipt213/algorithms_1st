#include "sort.hpp"

#include <vector>

std::vector<int> Join(std::vector<int>::iterator start_1, std::vector<int>::iterator end_1, std::vector<int>::iterator start_2, std::vector<int>::iterator end_2) {
  std::vector<int> result;
  while(start_1 < end_1 or start_2 < end_2) {
    if(start_1 == end_1) {
      result.push_back(*start_2);
      ++start_2;
    }
    else if(start_2 == end_2) {
      result.push_back(*start_1);
      ++start_1;
    }
    else if(*start_1 < *start_2) {
      result.push_back(*start_1);
      ++start_1;
    }
    else {
      result.push_back(*start_2);
      ++start_2;
    }
  }
  return result;
}

std::vector<int> Slice(const std::vector<int>& data, int start, int end) {
  std::vector<int> result;
  for (int i = start; i < end; ++i)
    result.push_back(data[i]);
  return result;
}

std::vector<int> MergeSort(const std::vector<int>& data) {
  if (data.size() <= 1)
    return data;
  std::vector<int> result;
  int middle = data.size() / 2;
  std::vector<int> data_l = MergeSort(Slice(data, 0, middle));
  std::vector<int> data_r = MergeSort(Slice(data, middle, data.size()));
  result = Join(data_l.begin(), data_l.end(), data_r.begin(), data_r.end());
  return result;
}
