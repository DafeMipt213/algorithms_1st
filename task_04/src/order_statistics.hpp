#pragma once

#include <vector>

void QuickSortRecursive(std::vector<int>& data, int left, int right);
int Partition(std::vector<int>& data, int left, int right);
int GetOrderStatistics(const std::vector<int>& data, std::size_t n);