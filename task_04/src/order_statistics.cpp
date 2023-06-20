#include "order_statistics.hpp"

void RandomVec(std::vector<int>& vec, size_t size) {
  for (int i = 0; i < size; i++) {
    int b = rand() % 1000 + 1;
    vec.push_back(b);
  }
}

std::vector<int> Sorted(std::vector<int> vec) {
  std::sort(vec.begin(), vec.end());
  return vec;
}

size_t Partition(std::vector<int>& vec, size_t left, size_t right) {
  int middle = vec[(left + right) / 2];
  while (true) {
    while (vec[left] < middle) left++;

    // if (vec[left] > vec[right]) std::swap(vec[right], vec[left]);

    while (vec[right] > middle) right--;

    if (vec[left] > vec[right] && left <= right)
      std::swap(vec[right], vec[left]);

    left += 1;

    if (left >= right) break;
  }
  return left;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
  std::vector<int> tmp(data);

  size_t left = 0;
  size_t right = data.size() - 1;

  while (true) {
    size_t pivot = Partition(tmp, left, right);

    if (pivot == n)
      return tmp[pivot];
    else if (pivot > n)
      right = pivot - 1;
    else
      left = pivot + 1;

    if (left == right) return tmp[left];
  }
}
