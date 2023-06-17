#include "order_statistics.hpp"

#include <algorithm>

namespace {

void SortLittleMassive(std::vector<int> &data, size_t start, size_t end) {
  if (end < start || end - start > 5) throw std::runtime_error("Wrong indexes");
  for (size_t i = start; i < end; ++i)
    for (size_t j = start; j < i; ++j)
      if (data[j] > data[i]) std::swap(data[i], data[j]);
}

int MedianMethod(std::vector<int> &data, size_t start, size_t end) {
  if (data.empty()) throw std::runtime_error("Empty massive");
  std::vector<int> medians;
  size_t i;
  for (i = start; i < end; i += 5) {
    SortLittleMassive(data, i, i + 5);
    medians.push_back(data[i + 2]);
  }
  if (i < end - 1) {
    SortLittleMassive(data, i, end);
    medians.push_back(data[(i + end) / 2]);
  }

  if (medians.size() <= 5) {
    SortLittleMassive(medians, 0, medians.size());
    return medians[medians.size() / 2];
  } else
    return MedianMethod(medians, 0, medians.size());
}

size_t Partition(std::vector<int> &data, size_t start, size_t end, int pivot) {
  size_t j = end;
  for (auto i = end - 1; i >= start; --i)
    if (data[j] > pivot) std::swap(data[--j], data[i]);
  std::swap(data[j - 1], data[start]);
  return j - 1;
}

int QuickSelect(std::vector<int> &data, int n, size_t start, size_t end) {
  int pivot = MedianMethod(data, start, end);
  size_t index = Partition(data, start, end, pivot);
  if (n == index) return pivot;
  return (n < index) ? QuickSelect(data, n, start, index + 1)
                     : QuickSelect(data, n, index + 1, end);
}

}  // namespace

int GetOrderStatistics(const std::vector<int> &data, size_t n) {
  if (data.empty()) throw std::runtime_error("Empty massive");
  if (data.size() <= n) throw std::runtime_error("Too big order statistic");
  std::vector<int> tmp(data);
  return QuickSelect(tmp, n, 0, tmp.size());
}
