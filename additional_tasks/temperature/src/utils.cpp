#include "utils.hpp"

#include <algorithm>

std::vector<int> CalculateDaysBeforWarmup(
    const std::vector<float>& temerature) {
  int n = temerature.size();
  std::vector<int> warm_ups(n);
  std::stack<float> higher_temps_stack;
  std::stack<int> index_stack;
  for (int i = temerature.size() - 1; i >= 0; --i) {
    if (higher_temps_stack.size() == 0) {
      higher_temps_stack.push(temerature[i]);
      index_stack.push(i);
      warm_ups[i] = 0;
    } else {
      if (higher_temps_stack.top() == temerature[i]) {
        index_stack.pop();
        warm_ups[i] = index_stack.top() - i;
        index_stack.push(i);
      } else if (higher_temps_stack.top() < temerature[i]) {
        while (higher_temps_stack.size() > 0 and
               higher_temps_stack.top() < temerature[i]) {
          higher_temps_stack.pop();
          index_stack.pop();
        }
        if (higher_temps_stack.size() == 0) {
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
