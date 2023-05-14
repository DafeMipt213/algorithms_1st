#include "sort.hpp"

#include <iostream>
#include <stack>
#include <vector>

size_t Partition(std::vector<int>& data, size_t left, size_t right) {
  // Выбираем рандомный pivot
  size_t pivot_index = left + rand() % (right - left + 1);
  size_t pivot = data[pivot_index];
  std::swap(data[pivot_index], data[right]);

  size_t i = left - 1;
  for (size_t j = left; j < right; j++) {
    if (data[j] <= pivot) {
      i++;
      std::swap(data[i], data[j]);
    }
  }
  std::swap(data[i + 1], data[right]);
  return i + 1;
}

// Quick Sort без рекурсии со Стеком :)
std::vector<int> Sort(const std::vector<int>& data) {
  std::vector<int> sorted_data = data;
  std::stack<std::pair<int, int>> stack;
  stack.push({0, data.size() - 1});

  while (!stack.empty()) {
    size_t l = stack.top().first;
    size_t r = stack.top().second;
    stack.pop();

    if (l >= r) continue;

    size_t pivot_index = Partition(sorted_data, l, r);

    stack.push({pivot_index + 1, r});
    stack.push({l, pivot_index - 1});
  }
  return sorted_data;
}