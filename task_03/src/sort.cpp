#include "sort.hpp"

std::vector<int>
Sort(std::vector<int> data)
{
  QuickSortRecursive(data, 0, static_cast<int>(data.size()) - 1);
  return data;
}

void
QuickSortRecursive(std::vector<int>& data, int left, int right)
{
  if (left < right) {
    int pivot_index = Partition(data, left, right);
    QuickSortRecursive(data, left, pivot_index - 1);
    QuickSortRecursive(data, pivot_index + 1, right);
  }
}

int
Partition(std::vector<int>& data, int start_index, int end_index)
{
  int pivot_value = data[end_index];
  int i = start_index - 1;
  for (int j = start_index; j < end_index; j++) {
    if (data[j] < pivot_value) {
      i++;
      std::swap(data[i], data[j]);
    }
  }
  std::swap(data[i + 1], data[end_index]);
  return i + 1;
}