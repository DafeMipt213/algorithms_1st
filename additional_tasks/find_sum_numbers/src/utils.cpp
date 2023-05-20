#include "utils.hpp"

#include <algorithm>

std::pair<int, int> GetNumbersOfSum(const std::vector<int>& numbers, int sum) {
  int i = 0;
  int j = numbers.size() - 1;
  while (i < j) {
    if (numbers[i] + numbers[j] == sum) {
      return {numbers[i], numbers[j]};
    }
    if (numbers[i] + numbers[j] > sum)
      --j;
    else {
      if (numbers[i] + numbers[j] < sum) ++i;
    }
  }
  return {};
}