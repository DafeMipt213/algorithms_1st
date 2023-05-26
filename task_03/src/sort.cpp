#include "sort.hpp"

#include <algorithm>
#include <vector>
 
size_t partition(std::vector<int>& data, size_t start, size_t end)
{
    int pivot = data[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (data[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    std::swap(data[pivotIndex], data[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (data[i] <= pivot)
            i++;
        while (data[j] > pivot)
            j--;
        if (i < pivotIndex && j > pivotIndex)
            std::swap(data[i++], data[j--]);
    }
    return pivotIndex;
}
 
std::vector<int> Sort(const std::vector<int> data, int start, int end)
{
    std::vector<int> sortedData = data;
    if (start < end){
    int p = partition(sortedData, start, end);
    sortedData = Sort(sortedData, start, p - 1);
    sortedData = Sort(sortedData, p + 1, end);
    }
    return sortedData;   
}