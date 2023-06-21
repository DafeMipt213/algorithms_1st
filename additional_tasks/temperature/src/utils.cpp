#include "utils.hpp"

#include <algorithm>

std::vector<int> CalculateDaysBeforWarmup(
    const std::vector<float>& temperature) {
  Stack<std::pair<float, int>> temperatures;
  std::vector<int> result(temperature.size());

  for (int i = 0; i < temperature.size(); ++i) {
    while (temperatures.Top().first < temperature[i]) {
      result[temperatures.Top().second] = i - temperatures.Top().second;
      temperatures.Pop();
    }
    temperatures.Push({temperature[i], i});
  }

  return result;
}
