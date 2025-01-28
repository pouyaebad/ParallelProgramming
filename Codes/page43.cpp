// Pre-requirement : Installing Intel oneAPI
//
// On Windows opt1 : icpx file_name.cpp
// On Windows opt2 : Visual Studio 
//                   Create “DPC++ Console” type project then in the solution
//                   explorer, right click on the project and in the 
//                   "Project Properties|Configuration|Intel libraries for oneAPI” 
//                   change value of “Use oneDAL” to "Default Linking Method" 
//

#include <oneapi/dpl/algorithm>
#include <oneapi/dpl/execution>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> nums{ 9, 4, 0, 3, 1, 6, -4, 7 };

   
    oneapi::dpl::sort(oneapi::dpl::execution::par, nums.begin(), nums.end());

    for (auto n : nums)
        std::cout << " " << n;

    std::cout << std::endl;
}

// Printed Result: -4 0 1 3 4 6 7 9
