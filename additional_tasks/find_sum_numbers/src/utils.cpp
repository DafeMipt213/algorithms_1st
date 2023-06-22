#include "utils.hpp"

#include <algorithm>

std::pair<size_t, size_t> GetNumbersOfSum(const std::vector<int> &numbers,
                                          int sum) {
  if (numbers.size() <= 1)
    throw std::out_of_range("Not enough elements in vector");
  size_t x = 0, y = numbers.size() - 1;
  while (numbers[x] + numbers[y] != sum && x != y)
    (numbers[x] + numbers[y] > sum) ? y-- : x++;
  if (x == y)
    throw std::runtime_error("There is no needed numbers in the vector");
  return std::make_pair(x, y);
}