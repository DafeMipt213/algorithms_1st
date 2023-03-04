#include "sort.hpp"
#include <iostream>
#include <vector>
int main() {
    std::cout << std::endl << std::endl << std::endl << std::endl;
    std::vector<int> a = {1, 1, 4, 3, 6, 7, 5, 8, 9, 1, 2};
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
    a = MergeSort(a);
    for(int i = 0; i < a.size(); ++i)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl << std::endl << std::endl << std::endl;
    return 0; }
