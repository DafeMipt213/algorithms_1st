#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int> &arr, int left, int middle, int right) {
  int left_half_size = middle - left + 1;
  int right_half_size = right - middle;

  vector<int> left_half(left_half_size);
  vector<int> right_half(right_half_size);

  for (int i = 0; i < left_half_size; i++) {
    left_half[i] = arr[left + i];
  }
  for (int i = 0; i < right_half_size; i++) {
    right_half[i] = arr[middle + 1 + i];
  }

  int i = 0;
  int j = 0;
  int k = left;
  while (i < left_half_size && j < right_half_size) {
    if (left_half[i] <= right_half[j]) {
      arr[k++] = left_half[i++];
    } else {
      arr[k++] = right_half[j++];
    }
  }

  while (i < left_half_size) {
    arr[k++] = left_half[i++];
  }
  while (j < right_half_size) {
    arr[k++] = right_half[j++];
  }
}

void MergeSort(vector<int> &arr, int left, int right) {
  if (left >= right) {
    return;
  }
  int middle = left + (right - left) / 2;
  MergeSort(arr, left, middle);
  MergeSort(arr, middle + 1, right);
  Merge(arr, left, middle, right);
}

vector<int> Sort(const vector<int> &data) {
  vector<int> result = data;
  MergeSort(result, 0, result.size() - 1);
  return result;
}
