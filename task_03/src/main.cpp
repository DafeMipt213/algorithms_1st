#include <iostream>

#include "sort.hpp"

int main() {
  std::vector<int> v1{1, 2, 1, 3};
  v1 = Sort(v1);
  Print(1, v1);
  return 0;
}
