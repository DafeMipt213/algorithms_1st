#pragma once
#include <stdexcept>
#include <vector>

int GetOrderStatistics(const std::vector<int>& data, size_t n);
int MedianOfMedians(const std::vector<int>& data);
int MedianSmall(const std::vector<int>& data);