#include "utils.hpp"

#include <algorithm>
#include <stack>

std::vector<int> CalculateDaysBeforWarmup(
    const std::vector<float>& temperature) {
  if (temperature.empty()) {
    return {};
  }
  std::stack<float> stack;
  std::stack<size_t> indexes_stack;
  std::vector<int> result{0};

  size_t last_elem_index = temperature.size() - 1;
  stack.push(temperature[last_elem_index]);
  indexes_stack.push(last_elem_index);

  for (int i = static_cast<int>(last_elem_index) - 1; i > -1; --i) {
    if (stack.empty()) {
      result.push_back(0);
      stack.push(temperature[i]);
      indexes_stack.push(i);
    } else if (temperature[i] < stack.top()) {
      result.push_back(indexes_stack.top() - i);
      stack.push(temperature[i]);
      indexes_stack.push(i);
    } else if (temperature[i] >= stack.top()) {
      stack.pop();
      indexes_stack.pop();
      i++;
    }
  }

  std::reverse(result.begin(), result.end());

  return result;
}
