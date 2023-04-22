#pragma once

#include <vector>

std::vector<int> MergeSort(const std::vector<int>& data);

std::vector<int> TakeVectorSlice(const std::vector<int>& data, int first_index,
                                 int last_index);
std::vector<int> Merge(const std::vector<int>& left,
                       const std::vector<int>& right);