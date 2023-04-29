#include "utils.hpp"

#include <algorithm>
#include <stack>

std::vector<int> CalculateDaysBeforWarmup(
    const std::vector<float>& temperature) {
  if (temperature.empty()) {
    return {};
  }
  std::stack<float> stack;
  std::stack<int> stackInd;
  std::vector<int> result{0};

  stack.push(temperature[temperature.size() - 1]);
  stackInd.push(temperature.size() - 1);

  for (int i = temperature.size() - 2; i > -1; --i) {
    if (stack.empty()) {
      result.push_back(0);
      stack.push(temperature[i]);
      stackInd.push(i);
    } else if (temperature[i] < stack.top()) {
      result.push_back(stackInd.top() - i);
      stack.push(temperature[i]);
      stackInd.push(i);
    } else if (temperature[i] >= stack.top()) {
      stack.pop();
      stackInd.pop();
      i++;
    }
  }

  std::reverse(result.begin(), result.end());

  return result;
}
