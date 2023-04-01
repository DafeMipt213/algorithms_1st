#include "sort.hpp"

#include <algorithm>
#include <vector>

std::vector<int> data_ = std::vector<int>(0);
std::vector<int>& sortData = data_;
void push(int n) {
  sortData.push_back(n);
  SiftUp();
}

void SiftUp() {
  int n = sortData[data_.size() - 1];
  int index = sortData.size() - 1;
  int i = index;
  while (i >= 0) {
    i = (index - 1) / 2;
    if (sortData[i] > sortData[index]) {
      int temp = sortData[i];
      sortData[i] = sortData[index];
      sortData[index] = temp;
    } else
      return;
  }
}

int Pop() {
  if (sortData.empty()) throw std::out_of_range("Empty heap");
  int result = sortData[0];
  sortData[0] = sortData[sortData.size() - 1];
  sortData.pop_back();
  SiftDown();
  return result;
}

void SiftDown() {
  if (sortData.size() == 0) return;
  int index = 0;
  int min_index = 0;
  while (2 * index + 1 <= sortData.size() - 1) {
    if (2 * index + 1 == sortData.size() - 1) {
      if (sortData[index] > sortData[2 * index + 1]) {
        int tmp = sortData[index];
        sortData[index] = sortData[2 * index + 1];
        sortData[2 * index + 1] = tmp;
      }
      return;
    } else {
      if (sortData[2 * index + 1] < sortData[2 * index + 2])
        min_index = 2 * index + 1;
      else
        min_index = 2 * index + 2;
      if (sortData[index] > sortData[min_index]) {
        int tmp = sortData[index];
        sortData[index] = sortData[min_index];
        sortData[min_index] = tmp;
        index = min_index;
      } else
        return;
    }
  }
}

std::vector<int> Sort(const std::vector<int>& data) {
  std::vector<int> result = std::vector<int>(0);
  for (int i = 0; i < data.size(); ++i) push(data[i]);
  for (int i = 0; i < data.size(); ++i) {
    int k = Pop();
    result.push_back(k);
    ;
  }
  return result;
}