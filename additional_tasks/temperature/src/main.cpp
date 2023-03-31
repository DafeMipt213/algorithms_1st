#include <iostream>
#include <stack>
#include <vector>

int main() {
  std::vector<int> arr = {4, 5, 3, 12, 3, 6, 4, 11, 11, 13};
  std::vector<int> ans(arr.size());
  std::stack<int> value_stack;
  std::stack<int> index_stack;
  value_stack.push(arr[arr.size() - 1]);
  index_stack.push(arr.size() - 1);
  ans[arr.size() - 1] = 0;
  for (size_t i = arr.size() - 2; i >= 0; --i) {
    if (arr[i] < value_stack.top()) {
      ans[i] = index_stack.top() - i;
      value_stack.push(arr[i]);
      index_stack.push(i);
    } else {
      while (value_stack.size() != 0 || arr[i] >= value_stack.top()) {
        value_stack.pop();
        index_stack.pop();
      }
      if (value_stack.size() == 0) {
        ans[i] == 0;
        value_stack.push(ans[i]);
        index_stack.push(i);
      } else {
        ans[i] == index_stack.top() - i;
        value_stack.push(arr[i]);
        index_stack.push(i);
      }
    }
  }
  for (size_t i = 0; i < arr.size(); ++i) {
    std::cout << ans[i] << ' ';
  }
  return 0;
}
