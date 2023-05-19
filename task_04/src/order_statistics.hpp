#pragma once

#include <vector>

int GetOrderStatistics(const std::vector<int>& data, size_t n);
size_t Partition(std::vector<int>& data, size_t left, size_t right);
void RandomVec(std::vector<int>& vec, size_t size);
std::vector<int> Sorted(std::vector<int> vec);