#include "order_statistics.hpp"

int random_int(int a, int b){
  std::random_device rd;
  std::mt19937 mt(rd());
  std::uniform_real_distribution<> dist(a, b);

  int random_int = dist(mt);
  return random_int;
}
