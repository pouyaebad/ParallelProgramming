// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp -std=c++11
// On Windows      : Visual Studio (MSVC)
//

#include <iostream>
#include <thread>



void f(int *numbers, int *sum)
{
    *sum = *numbers + *(numbers+1);
}



int main()
{
    int nums[] = { 33, 12, -5, 15 };
    int subTot[2];

    std::thread t1(f, &(nums[0]), &(subTot[0]));  // Creating thread 1 & running it
    std::thread t2(f, &(nums[2]), &(subTot[1]));  // Creating thread 2 & running it


    t1.join();           // Wait for thread 1 to finish
    t2.join();           // Wait for thread 2 to finish

    int grand_total{ subTot[0] + subTot[1]};
    std::cout << "Sum of all numbers is: " << grand_total << std::endl;
}
// Printed Result: 55
