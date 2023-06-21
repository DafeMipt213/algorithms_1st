#include "utils.hpp"

#include <algorithm>

std::pair<int, int> GetNumbersOfSum(const std::vector<int>& numbers, int sum) {
  int pointer1 = 0;
  int pointer2 = numbers.size() - 1;

  int temp_sum = numbers[pointer1] + numbers[pointer2];
  while (temp_sum != sum && pointer1 != pointer2) {
    if (temp_sum < sum)
      pointer1++;
    else if (temp_sum > sum)
      pointer2++;
    else
      break;
    temp_sum = numbers[pointer1] + numbers[pointer2];
  }
  if (numbers[pointer1] + numbers[pointer2] == sum) return {pointer1, pointer2};

  return {0, 0};
}