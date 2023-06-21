#pragma once

#include <vector>

int GetOrderStatistics(std::vector<int>& data, size_t n);

int FindOrderStatistic(std::vector<int>& vec, int low, int high, int k);

int FindMedian(std::vector<int> vec, int low, int med, int high);

int BreakPartition(std::vector<int>& vec, int low, int high);
