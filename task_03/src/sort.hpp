#pragma once

#include <vector>

std::vector<int> Sort(std::vector<int> data);

void QuickSortRecursive(std::vector<int>& data, int start_index, int end_index);

int Partition(std::vector<int>& data, int start_index, int end_index);