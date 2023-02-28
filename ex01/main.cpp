#include "iter.hpp"

#include <iostream>

void printarray(int& x)
{
    std::cout << x << " ";
}

int main() 
{
    int arr[] = {1, 2, 3, 4, 5};
    int length = sizeof(arr) / sizeof(int);

    iter(arr, length, printarray);
    std::cout << std::endl;
    return 0;
}