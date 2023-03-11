#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v{1,2,3};
    std::cout << *(&v.front()+1) << '\n';
    return 0; 
}
