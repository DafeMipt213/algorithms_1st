#include "order_statistics.hpp"

int Partition(std::vector<int>& data, size_t left, size_t right) {
  int pivot = data[(left + right + 1) / 2];
  while (left <= right) {
    while (data[left] < pivot) left++;

    while (data[right] > pivot) right--;

    if (left >= right) break;
    std::swap(data[right], data[left]);
    left++;
    right--;
  }

  return left;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  size_t Left = 0;
  size_t Right = data.size() - 1;
  std::vector<int> tmp = data;

  while (true) {
    size_t mid = Partition(tmp, Left, Right);

    if (n < mid)
      Right = mid;
    else if (n > mid)
      Left = mid;
    else
      return tmp[mid];
  }
}