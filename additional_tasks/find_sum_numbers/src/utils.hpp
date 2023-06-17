#pragma once
#include <stdexcept>
#include <vector>

std::pair<size_t, size_t> GetNumbersOfSum(const std::vector<int>& numbers,
                                          int sum);
