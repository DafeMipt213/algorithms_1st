#include <iostream>
#include "sort.hpp"
#include <vector>
using namespace std;
int main() 
{ 
    vector<int> arr{38, 27, 43, 3, 9, 82, 10};  
    arr = Sort(arr); 
 
    cout << "Sorted array is: "; 
    for (int i = 0; i < arr.size(); i++) { 
        cout << arr[i] << " "; 
    } 
 
    return 0; 
}
