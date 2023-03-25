#include <iostream>
#include <stack>
#include <vector>

#include "utils.hpp"

int main() {
  std::vector<float> days{
      4, 5, 3,  12, 3,
      6, 4, 11, 11, 13};  //-> {1, 3, 3, 9, 5, 7, 9, 9, 0} NOLINT
  std::vector<int> warm_ups = CalculateDaysBeforWarmup(days);
  for (int i = 0; i < days.size(); ++i) {
    std::cout << warm_ups[i] << " ";
  }

  return 0;
}
