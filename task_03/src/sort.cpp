#include "sort.hpp"

void quickSort(std::vector<int>::iterator array, int low, int hight) {
  int i = low;
  int j = hight;
  int pivot = array[(i + j) / 2];
  int temp{0};

  while (i <= j) {
    while (array[i] < pivot) i++;
    while (array[j] > pivot) j--;
    if (i <= j) {
      temp = array[i];
      array[i] = array[j];
      array[j] = temp;
      i++;
      j--;
    }
  }

  if (j > low) quickSort(array, low, j);
  if (i < hight) quickSort(array, i, hight);
}

void printArr(std::vector<int>::iterator array, int n) {
  for (int i = 0; i < n; i++) std::cout << array[i] << " ";
}

std::vector<int> Sort(std::vector<int> vec) {
  if (vec.size() == 0) return {};
  std::vector<int>::iterator i = vec.begin();
  quickSort(i, 0, (int)vec.size() - 1);
  printArr(vec.begin(), (int)vec.size());
  return vec;
}