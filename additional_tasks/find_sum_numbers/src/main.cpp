#include <iostream>
#include <vector>

#include "utils.hpp"

int main() {
  std::vector<int> test = {-10, -2, 0, 3, 6, 7, 11, 14};
  std::pair<int, int> p = GetNumbersOfSum(test, 3);
  std::cout << p.first << " " << p.second << '\n';
}
