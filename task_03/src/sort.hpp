#pragma once

#include <vector>

std::vector<int> MergeSort(const std::vector<int>& data);

std::vector<int> Merge(const std::vector<int>& data1,
                       const std::vector<int>& data2);

std::vector<int> SplitLeft(const std::vector<int>& data);

std::vector<int> SplitRight(const std::vector<int>& data);
