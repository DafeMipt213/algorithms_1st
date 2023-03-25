#include <iostream>
#include <order_statistics.hpp>

int main() {
  std::vector<int> p{1, 2, 5, 1, 7, 9, 11, 213, 12, 51, 17, 99};    // NOLINT
  std::vector<int> med{1, 2, 5, 1, 7, 9, 11, 213, 12, 51, 17, 99};  // NOLINT
  std::cout << MedianOfMedians(med) << " ";
  std::cout << GetOrderStatistics(p, 1);
}
