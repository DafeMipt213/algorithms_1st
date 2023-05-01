#include <iostream>

#include "order_statistics.hpp"
#include "vector"

int main() {
  std::vector<int> data{1, 2, 5, 1, 7, 9, 11, 213, 12, 51, 17, 99};
  std::cout << GetOrderStatistics(data, 1) << std::endl;
  std::cout << GetOrderStatistics(data, 2) << std::endl;
  std::cout << GetOrderStatistics(data, 3) << std::endl;
  std::cout << GetOrderStatistics(data, 4) << std::endl;
  std::cout << GetOrderStatistics(data, 10) << std::endl;
  return 0;
}
