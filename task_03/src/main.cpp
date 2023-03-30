#include <iostream>
#include <sort.hpp>

int main() { 
    std::vector<int> a {1,6,4,7, 11};
    
    std::vector<int> res = Sort(a);
    for (int i = 0; i < res.size(); ++i){
        std::cout << res[i];
    }
    return 0; 
}
