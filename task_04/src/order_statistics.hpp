#pragma once

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

int random_int(int a, int b);
// TODO TESTS
template <typename T>
int GetOrderStatistics(const std::vector<T>& data, size_t n) {
  int size = data.size() - 1;
  if (size == 0 && n == 0)
    return data[0];
  else if (size == 0 && n != 0)
    return data[size];
  else if (size == 1 && n == 0)
    return std::min(data[0], data[size]);
  else if (size == 1 && n == 1)
    return std::max(data[0], data[size]);

  int random_index = random_int(1, size - 1);
  int item = data[random_index];

  std::vector<T> first;
  std::vector<T> second;
  std::vector<T> third;

  for (int i = 0; i <= size; i++) {
    if (data[i] < item)
      first.push_back(data[i]);
    else if (data[i] == item)
      second.push_back(data[i]);
    else
      third.push_back(data[i]);
  }

  if (n < first.size())
    return GetOrderStatistics(first, n);
  else if (n < second.size() + first.size())
    return item;
  else
    return GetOrderStatistics(
        third,
        n - first.size() - second.size());  // n - номер порядковой статистики,
                                            // а не размер массива
}