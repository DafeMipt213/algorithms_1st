#include <iostream>
#include "tree.hpp"
int main() {
    Tree ntr;
    ntr.InsertOrUpdate(7, 11);
    ntr.InsertOrUpdate(6, 7);
    ntr.InsertOrUpdate(6, 5);
    std::cout << ntr.Find(7) << std::endl;
    std::cout << ntr.Find(6) << std::endl;
}
