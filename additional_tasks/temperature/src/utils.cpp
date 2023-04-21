#include "utils.hpp"

#include <algorithm>
#include <stack>

std::vector<int> CalculateDaysBeforWarmup(
    const std::vector<float>& temerature) {
  std::vector<int> warm_ups(temerature.size());
  std::stack<float> higher_temps_stack;
  std::stack<int> index_stack;
  for (int i = temerature.size() - 1; i >= 0; --i) {
    if (higher_temps_stack.empty()) {
      higher_temps_stack.push(temerature[i]);
      index_stack.push(i);
      warm_ups[i] = 0;
    } else {
      if (higher_temps_stack.top() == temerature[i]) {
        index_stack.pop();
        warm_ups[i] = index_stack.top() - i;
        index_stack.push(i);
      } else if (higher_temps_stack.top() < temerature[i]) {
        while (!higher_temps_stack.empty() &&
               higher_temps_stack.top() < temerature[i]) {
          higher_temps_stack.pop();
          index_stack.pop();
        }
        if (higher_temps_stack.empty()) {
          higher_temps_stack.push(temerature[i]);
          index_stack.push(i);
          warm_ups[i] = 0;
        } else {
          warm_ups[i] = index_stack.top() - i;
          higher_temps_stack.push(temerature[i]);
          index_stack.push(i);
        }
      } else {
        warm_ups[i] = index_stack.top() - i;
        higher_temps_stack.push(temerature[i]);
        index_stack.push(i);
      }
    }
  }
  return warm_ups;
}
