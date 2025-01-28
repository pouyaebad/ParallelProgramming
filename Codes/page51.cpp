// Pre-requirement : None
// 
// On Linux        : g++ ./file_name.cpp  -fopenmp
// On Windows      : Visual Studio (MSVC), 
//                   In the solution explorer, right click on the project & in the 
//                   "Project Properties | Configuration | C/C++ | Language” 
//                   change value of “openMP Support” to “yes”  
//

#include <iostream>
#include <chrono>   // only for sleep function
#include <thread>   // only for sleep function
#include <vector>
#include <omp.h>

int main()
{
	#pragma omp parallel sections
	{
			#pragma omp section
			{
			    std::cout << "1 Start" << std::endl;
			    std::this_thread::sleep_for(std::chrono::milliseconds(50));
			    std::cout << "1 End" << std::endl;
			}

			#pragma omp section
			{
			    std::this_thread::sleep_for(std::chrono::milliseconds(30));
			    std::cout << "2 All" << std::endl;
			}
	}

	std::vector<int> v(10);

	#pragma omp parallel for
		for (int index = 0; index < 10; index++)
			v[index] = index * index;

	for (auto n : v)
		std::cout << " " << n;

	std::cout << std::endl;
}

// Printed Result on Screen: 1 Start
//                           2 All
//                           1 End
//                           0 1 4 9 16 25 36 49 64 81
