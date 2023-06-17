#include "order_statistics.hpp"

#include <algorithm>

int Partition(std::vector<int>& a, int start, int end) {
    int l = start, r = end;
    if (l!=r)
        std::swap(a[l + rand() % (r - l)], a[r]);
    int x = a[r];
    int i = l-1;
    for (int j = l; j <= r; j++) {
        if (a[j] <= x)
            std::swap(a[++i],a[j]);
    }
    return i;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
    std::vector<int> tmp(data);
    int left = 0, right = tmp.size() - 1;
    while (true) {
        int m = Partition(tmp, left, right);
        if (m == n) {
            return tmp[m];
        }
        else if (n < m) {
            right = m - 1;
        }
        else {
            left = m + 1;
        }
    }
}