/*

#include "sort.hpp"

#include <algorithm>
#include <vector>

std::vector<int> Sort(const std::vector<int>& data) {
  std::vector<int> result = data;
  int size = result.size();

  for (int step = 1; step < size; step += step) {for (i= 0; i< size ; i +=1
  }
}

return result;
}


*/

#include <algorithm>
#include <vector>

#include "sort.hpp"

std::vector<int> Sort(const std::vector<int>& data) { return MergeSort(data); }

std::vector<int> MergeSort(std::vector<int> data) {
  if (data.size() == 1) {
    return data;
  }
  std::vector<int> left(data.begin(), data.begin() + (data.size() / 2));
  std::vector<int> right(data.begin() + (data.size() / 2) + 1, data.end());
  return Merge(MergeSort(left), MergeSort(right));
}

std::vector<int> Merge(const std::vector<int>& left,
                       const std::vector<int>& right) {
  std::vector<int> output;
  int i = 0;
  int j = 0;
  while (i < left.size() || j < right.size()) {
    if (i < left.size() && j < right.size()) {
      if (left[i] <= right[j]) {
        output.push_back(left[i]);
        ++i;
      } else {
        output.push_back(right[j]);
        ++j;
      }

    } else if (i >= left.size()) {
      output.push_back(right[j]);
      ++j;
    } else if (j >= right.size()) {
      output.push_back(left[i]);
      ++j;
    }
  }
  return output;
}
