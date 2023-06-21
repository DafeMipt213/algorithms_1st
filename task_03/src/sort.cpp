#include "sort.hpp"

#include <algorithm>
#include <vector>
/*
def bose_nelson_merge(j, r, m):
    if j + r < len(data):
        if m == 1:
            if data[j] > data[j + r]:
                data[j], data[j + r] = data[j + r], data[j]
        else:
            m = m // 2
            bose_nelson_merge(j, r, m)
            if j + r + m < len(data):
                bose_nelson_merge(j + m, r, m)
            bose_nelson_merge(j + m, r - m, m)
    return data
*/
/*
void Merge(int j, int r, int m) {
  if (j + r < data.size()) {
    if (m == 1) {
      if ( data[j] > data[j + r]) {
        int buffer = data[j];
        data[j] =  data[j + r];
        data[j + r] = data[j];
      }
    }
  }
}
*/
//what
std::vector<int> Sort(const std::vector<int>& data) {
  std::vector<int> result = data;

  std::sort(result.begin(), result.end());
  
  return result;
}