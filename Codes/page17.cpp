// Pre-requirement : None
//
// On Linux        : g++ ./file_name.cpp  -std=c++11
// On Windows      : Visual Studio (MSVC): use switch /std:c++11
//

#include <iostream>
#include <thread>


void f(int* numbers, int* sum)
{
    int total_this_thread = *sum;
    
    total_this_thread += *numbers;
    total_this_thread += *(numbers + 1);

    std::cout << "Total of this thread is: " << total_this_thread << std::endl;

    *sum = total_this_thread;
}


int main()
{
    int numbers[] = { 33, 12, -5, 15 };
    int grandTot {};

    std::thread t1(f, &(numbers[0]), &grandTot); // Creating thread 1 & running it
    std::thread t2(f, &(numbers[2]), &grandTot); // Creating thread 2 & running it


    t1.join();           // Wait for thread 1 to finish
    t2.join();           // Wait for thread 2 to finish

    std::cout << "Sum of all numbers is: " << grandTot << std::endl;
}

// Result (grandTot) can be different in different runs; it can be 10 or 45 or 55
