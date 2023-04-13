#pragma once

#include <vector>

std::vector<int> Sort(std::vector<int> data);

void QuickSortRecursive(std::vector<int>& data, int left, int right);

int Partition(std::vector<int>& data, int left, int right);
