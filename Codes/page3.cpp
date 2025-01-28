// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp  -std=c++17
// On Windows      : Visual Studio (MSVC): use switch /std:c++17
//

#include <iostream>
#include <vector>
#include <execution>


int main()
{
    std::vector<int> nums{ 9, 4, 0, 3, 1, 6, -4, 7 };

    std::sort(std::execution::par, nums.begin(), nums.end()); // Data Parallel

    for(auto n : nums)
        std::cout << " " << n;
}

// Printed Result: -4 0 1 3 4 6 7 9
