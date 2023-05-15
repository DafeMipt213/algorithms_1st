#include <algorithm>
#include <iostream>
#include <vector>

int GetOrderStatistics(std::vector<int>& data, size_t n) {
  int left = 0;
  int right = data.size() - 1;
  while (left < right) {
    int pivotIndex = left;
    int pivotValue = data[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
      if (data[i] > pivotValue && data[j] <= pivotValue) {
        std::swap(data[i], data[j]);
        i++;
        j--;
      }
      if (data[i] <= pivotValue) {
        i++;
      }
      if (data[j] > pivotValue) {
        j--;
      }
    }
    std::swap(data[pivotIndex], data[j]);

    if (j == n) {
      return data[j];
    } else if (j < n) {
      left = j + 1;
    } else {
      right = j - 1;
    }
  }
  return data[left];
}
