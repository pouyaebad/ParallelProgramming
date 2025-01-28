// Pre-requirement : Installing Intel oneAPI
//
// On Windows opt1 : icpx file_name.cpp
// On Windows opt2 : Visual Studio 
//                   Create “DPC++ Console” type project then in the solution
//                   explorer, right click on the project and in the 
//                   "Project Properties|Configuration|Intel libraries for oneAPI” 
//                   change value of “Use oneTBB” to “yes”  
//
#include <vector>
#include <iostream>

#include <tbb/blocked_range.h>
#include <tbb/parallel_for.h>
#include "tbb/parallel_invoke.h"

void f(int a)
{
    std::cout << "From Function f(), a = " << a << std::endl;
}

int main()
{
    std::vector<int> v(10);

    tbb::parallel_for(tbb::blocked_range<int>(0, v.size()),
        [&](tbb::blocked_range<int> r)
        {
            for (int index = r.begin(); index < r.end(); ++index)
                v[index] = index * index;
        });


    for (auto n : v)
        std::cout << " " << n;
    std::cout << std::endl;

    tbb::parallel_invoke([] {f(2); }, [] {f(5); });
}

// Printed Result on Screen: 0 1 4 9 16 25 36 49 64 81
//                           From Function f(), a = 5
//                           From Function f(), a = 2
