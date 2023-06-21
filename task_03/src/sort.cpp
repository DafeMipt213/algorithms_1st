#include "sort.hpp"

void QuickSort(std::vector<int>::iterator array, size_t low, size_t hight) {
  int i = low;
  int j = hight;
  int pivot = array[(i + j) / 2];
  int temp{0};

  while (i <= j) {
    while (array[i] < pivot) i++;
    while (array[j] > pivot) j--;
    if (i <= j) {
      std::swap(array[i], array[j]);
      i++;
      j--;
    }
  }

  if (j > low) QuickSort(array, low, j);
  if (i < hight) QuickSort(array, i, hight);
}

void PrintVector(std::vector<int>::iterator array, int n) {
  for (int i = 0; i < n; i++) std::cout << array[i] << " ";
}

std::vector<int> Sort(std::vector<int> vec) {
  if (vec.size() == 0) return {};
  if (vec.size() == 1) return vec;
  std::vector<int>::iterator i = vec.begin();
  QuickSort(i, 0, (int)vec.size() - 1);
  return vec;
}