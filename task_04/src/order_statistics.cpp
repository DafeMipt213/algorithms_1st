#include "order_statistics.hpp"

#include <algorithm>

namespace {

void SortLittleMassive(std::vector<int> &data) {
  for (int i = 0; i < data.size(); ++i)
    for (int j = i + 1; j < data.size(); ++j)
      if (data[j] < data[i]) std::swap(data[i], data[j]);
}

int MedianMethod(const std::vector<int> &data, int start, int end) {
  if (data.empty()) throw std::runtime_error("Empty massive");
  if (start == end - 1) return data[start];
  std::vector<int> medians;
  int i = start;
  if (end - start >= 5)
    for (; i < end - 5; i += 5) {
      std::vector<int> tmp =
          std::vector<int>(data.begin() + i, data.begin() + i + 5);
      SortLittleMassive(tmp);
      medians.push_back(data[i + 2]);
    }
  if (i < end - 1) {
    std::vector<int> tmp =
        std::vector<int>(data.begin() + i, data.begin() + end);
    SortLittleMassive(tmp);
    medians.push_back(data[(i + end) / 2]);
  }

  if (medians.size() <= 5) {
    SortLittleMassive(medians);
    return medians[medians.size() / 2];
  } else
    return MedianMethod(medians, 0, medians.size());
}

int PivotIndex(std::vector<int> &data, int start, int end, int pivot) {
  for (int i = start; i < end; ++i)
    if (data[i] == pivot) return i;
  throw std::runtime_error("There is no any such element");
}

int Partition(std::vector<int> &data, int start, int end) {
  int pivot = MedianMethod(data, start, end);
  int pivot_idx = PivotIndex(data, start, end, pivot);
  std::swap(data[pivot_idx], data[end - 1]);
  int j = start - 1;
  for (auto i = start; i < end; ++i) {
    if (data[i] < pivot) {
      ++j;
      std::swap(data[j], data[i]);
    }
  }
  std::swap(data[j + 1], data[end - 1]);
  return j + 1;
}

int QuickSelect(std::vector<int> &data, int n, int start, int end) {
  int index = Partition(data, start, end);
  if (n == index + 1) return data[index];
  return (n < index + 1) ? QuickSelect(data, n, start, index)
                         : QuickSelect(data, n, index + 1, end);
}

}  // namespace

int GetOrderStatistics(const std::vector<int> &data, int n) {
  if (data.empty()) throw std::runtime_error("Empty massive");
  if (data.size() < n) throw std::runtime_error("Too big order statistic");
  std::vector<int> tmp(data);
  return QuickSelect(tmp, n, 0, tmp.size());
}
