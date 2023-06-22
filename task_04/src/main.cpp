#include <iostream>

#include "order_statistics.hpp"

int main() {
  std::cout << "************************" << std::endl;
  std::vector<int> v{1, 2, 5, 7, 9, 11, 213, 12, 51, 17, 99};
  std::cout << GetOrderStatistics(v, 4) << " answer " << std::endl;
}