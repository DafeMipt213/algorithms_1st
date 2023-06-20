#include <iostream>
#include <vector>

#include "utils.hpp"

void print(const std::vector<int>& v) {
  for (int i = 0; i < v.size(); ++i) {
    std::cout << v[i] << " ";
  }
  std::cout << '\n';
}

int main() {
  std::vector<float> temp{10, 11, 8, 12};
  std::vector<int> v = CalculateDaysBeforWarmup(temp);
  print(v);
  return 0;
}
