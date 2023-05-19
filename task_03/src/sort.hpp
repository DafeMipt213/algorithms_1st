#pragma once

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

void QuickSort(std::vector<int>::iterator array, size_t low, size_t hight);
void PrintVector(std::vector<int>::iterator array, int n);
std::vector<int> Sort(std::vector<int> vec);
void CreateRandomVec(std::vector<int>& vec, size_t size);
void RandomFill(std::vector<int>& vec, size_t size);
std::vector<int> Sorted(std::vector<int> vec);