#include "sort.hpp"

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using iter = vector<int>::iterator;

void merge(iter left, iter mid, iter right) {
  vector<int> leftVec(left, mid);
  vector<int> rightVec(mid, right);

  iter lidx = leftVec.begin();
  iter ridx = rightVec.begin();

  while (lidx != leftVec.end() and ridx != rightVec.end()) {
    if (*lidx < *ridx) {
      *left = *lidx;
      ++lidx;
    } else {
      *left = *ridx;
      ridx++;
    }
    left++;
  }

  copy(lidx, leftVec.end(), left);
}

void Sort1(iter left, iter right) {
  int dist = distance(left, right);
  if (dist > 1) {
    iter mid = left + (dist) / 2;

    Sort1(left, mid);
    Sort1(mid, right);

    merge(left, mid, right);
  }
}

// void Sort(iter left, iter right) {
vector<int> Sort(vector<int> vec) {
  if (vec.size() > 1) {
    iter left = vec.begin();
    iter right = vec.end();
    Sort1(left, right);
  }

  return vec;
}
