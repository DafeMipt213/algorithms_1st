#include "order_statistics.hpp"

#include <algorithm>

size_t partition(std::vector<int>& data, size_t start, size_t end)
{
    int pivot = data[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (data[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    std::swap(data[pivotIndex], data[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (data[i] <= pivot)
            i++;
        while (data[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            std::swap(data[i++], data[j--]);
    }
    return pivotIndex;
}

int GetOrderStatistics(std::vector<int>& data, size_t k) {
  int left = 0, right = data.size() - 1;
  while (true) {
    size_t pivotIndex = partition(data, left, right);
    if (pivotIndex == k) {
      return data[pivotIndex];
    }
    else if (k < pivotIndex)
      right = pivotIndex;
    else
      left = pivotIndex + 1;
  }
}
