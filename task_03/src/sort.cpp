#include "sort.hpp"

#include <vector>
#include <stack>


int partition(std::vector<int>& data, int l, int r)
{
    // Выбираем рандомный pivot
    int pivot_index = l + rand() % (r - l + 1);
    int pivot = data[pivot_index];
    std::swap(data[pivot_index], data[r]);

    int i = l - 1;
    for (int j = l; j < r; j++)
    {
        if (data[j] <= pivot)
        {
            i++;
            std::swap(data[i], data[j]);
        }
    }
    std::swap(data[i+1], data[r]);
    return i+1;
}

// Quick Sort без рекурсии
std::vector<int> Sort(const std::vector<int>& data) {
    std::vector<int> sorted_data = data;
    std::stack<std::pair<int, int>> s;
    s.push({0, data.size()-1});

    while (!s.empty())
    {
        int l = s.top().first;
        int r = s.top().second;
        s.pop();

        if (l >= r)
            continue;

        int pivot_index = partition(sorted_data, l, r);

        s.push({pivot_index + 1, r});
        s.push({l, pivot_index - 1});
    }
    return sorted_data;
}