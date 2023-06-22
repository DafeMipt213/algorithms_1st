#include "Merge_Sort.hpp"
void merge(std::vector<int>& a, int start, int end, int mid){
    std::vector<int> merged;
    int i = start;
    int j = mid + 1;
    while (i <= mid && j <= end) {
        if (a[i] < a[j]) {
            merged.push_back(a[i]);
            i++;
        }
        else {
            merged.push_back(a[j]);
            j++;
        }
    }

    while (i <= mid) {
        merged.push_back(a[i]);
        i++;
    }

    while (j <= end) {
        merged.push_back(a[j]);
        j++;
    }
    for (int i = start; i <= end; ++i)
        a[i] = merged[i - start];
}

std::vector<int> merge_sort(std::vector<int>& a, int start, int end) {
    if (start < end) {
        int pivot = (start + end) / 2;
        merge_sort(a, start, pivot);
        merge_sort(a, pivot + 1, end);
        merge(a, start, end, pivot);
    }
    return a;
}

std::vector<int> Sort(const std::vector<int>& data) {
    std::vector<int> tmp(data);
    return merge_sort(tmp, 0, tmp.size() - 1);
}