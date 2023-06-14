#include "order_statistics.hpp"

void QuickSortRecursive(std::vector<int>& data, int left, int right) {
    if (left < right) {
        int pivot_index = Partition(data, left, right);
        QuickSortRecursive(data, left, pivot_index - 1);
        QuickSortRecursive(data, pivot_index + 1, right);
    }
}

int Partition(std::vector<int>& data, int left, int right) {
    int pivot_value = data[right];
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (data[j] < pivot_value) {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i + 1], data[right]);
    return i + 1;
}

int GetOrderStatistics(const std::vector<int>& data, size_t n) {
    std::vector<int> tmp(data);

    QuickSortRecursive(tmp, 0, tmp.size() - 1);

    return tmp[n];
}