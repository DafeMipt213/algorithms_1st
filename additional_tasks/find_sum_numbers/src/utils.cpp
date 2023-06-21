#include "utils.hpp"

#include <algorithm>

std::pair<int, int> GetNumbersOfSum(const std::vector<int>& numbers, int sum) {
  int left = 0;
  int right = numbers.size() - 1;
  while (left < right) {
    if (numbers[left] + numbers[right] == sum) {
      return {left, right};
    } else if (numbers[left] + numbers[right] > sum) {
      right -= 1;
    } else {
      left += 1;
    }
  }
  return {-1, -1};
}