// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp  -std=c++20
// On Windows      : Visual Studio (MSVC): use switch /std:c++20
//

#include <iostream>
#include <vector>
#include <execution>


int main()
{
    std::vector<int> nums{ 9, 4, 0, 3, 1, 6, -4, 7 };

    std::sort(std::execution::unseq, nums.begin(), nums.end()); // vectorized

    for(auto n : nums)
        std::cout << " " << n;
}

// Printed Result: -4 0 1 3 4 6 7 9
