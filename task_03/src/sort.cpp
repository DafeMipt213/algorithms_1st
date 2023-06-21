#include "sort.hpp"

void qsort(std::vector<int>::iterator a, size_t low, size_t hight) {
  int i = low;
  int j = hight;
  int pivot = a[(i + j) / 2];
  int temp{0};

  while (i <= j) {
    while (a[i] < pivot) i++;
    while (a[j] > pivot) j--;
    if (i <= j) {
      std::swap(a[i], a[j]);
      i++;
      j--;
    }
  }

  if (j > low) 
    qsort(a, low, j);
  if (i < hight) 
    qsort(a, i, hight);
}

std::vector<int> Sort(std::vector<int> vec) {
  if (vec.size() == 0) return {};
  if (vec.size() == 1) return vec;
  std::vector<int>::iterator i = vec.begin();
  qsort(i, 0, (int)vec.size() - 1);
  return vec;
}