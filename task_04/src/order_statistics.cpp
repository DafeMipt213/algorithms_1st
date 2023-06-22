#include <algorithm>
#include <iostream>
#include <vector>

int GetOrderStatistics(std::vector<int>& data, size_t n) {
  int left = 0;
  int right = data.size() - 1;
  while (left < right) {
    int pivot_index = left;
    int pivot_value = data[left];
    int i = left + 1;
    int j = right;
    while (i <= j) {
      if (data[i] > pivot_value && data[j] <= pivot_value) {
        std::swap(data[i], data[j]);
        i++;
        j--;
      }
      if (data[i] <= pivot_value) {
        i++;
      }
      if (data[j] > pivot_value) {
        j--;
      }
    }
    std::swap(data[pivot_index], data[j]);

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
